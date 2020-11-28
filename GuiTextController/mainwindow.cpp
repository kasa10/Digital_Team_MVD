#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qdebug.h"
#include <regex>
#include <fstream>
#include <sstream>
#include <string>
#include "machinelearnitem.h"
#include "qmessagebox.h"
#include "forms/totallyeditordialog.h"


std::string getDbPathFromConfigFile()
{
    auto ss = std::ostringstream{};
    std::ifstream file("config.txt");
    ss << file.rdbuf();
    auto input = ss.str();
    input.erase(std::remove(input.begin(), input.end(), '\r'),
                input.end());
    input.erase(std::remove(input.begin(), input.end(), '\n'),
                input.end());
    return input;
}

std::string parseStringWithoutQuotes(std::string str)
{
    const char* token = "\"";
    size_t pos1 = 0, pos2 = 0;

    while ( (pos1 = str.find(token, pos1)) != std::string::npos &&
            (pos2 = str.find(token, pos1 + 1)) != std::string::npos )
        str.erase( pos1, pos2 - pos1 + 1 );

    return str;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    engine = new HandlerEngine(getDbPathFromConfigFile());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered() //Выполнить автозамену
{
    if(!ui->txtInput->toPlainText().isEmpty())
    {
        auto inn = ui->txtInput->toPlainText().toStdString();
        inn = parseStringWithoutQuotes(inn);
        auto input = engine->getTextObject(inn);
        auto outputText = ui->txtInput->toPlainText();

        std::vector<std::string> input_words;
        Sex sex;
        Counting counting;

        //определение единственного и множественного числа
        if(ui->checkBox->isChecked()) counting=Counting::Plural;
            else counting=Counting::Single;

        //мужской или женский пол
        if(ui->radioButton_2->isChecked()) sex = Sex::Male;
            else if(ui->radioButton->isChecked()) sex = Sex::Female;

        //наполнение словами
        for(auto p: input.paragraphs)
        {
            for(auto s: p.sentences)
            { for(auto w: s.words)
                { input_words.push_back(w); } }
        }


        //основной ход алгоритма
        QStringList highlight_words;
        if(input_words.size()>0)
        {
            for(unsigned long long i=0; i<input_words.size(); i++)
            {
                if( input_words[i]!="я "
                        && input_words[i]!=" я "
                        && input_words[i]!="Я "
                        && input_words[i]!=" я"
                        && input_words[i]!=" Я "
                        && input_words[i]!="я"
                        && input_words[i]!="Я")
                {
                    auto keyword = engine->getThirdFaceRuleByFirstFace(input_words[i], sex, counting);
                    if(keyword!="")
                    {
                        highlight_words.append(QString::fromStdString(keyword));
                        outputText = outputText.replace(QString::fromStdString(input_words[i]), QString::fromStdString(keyword));
                    }
                }
                else
                {
                    outputText = outputText.replace("Я ", ui->lineEdit->text()+" ");
                    outputText = outputText.replace(" я ", " "+ui->lineEdit->text()+" ");
                    outputText = outputText.replace(" Я ", " "+ui->lineEdit->text()+" ");
                    outputText = outputText.replace("Я, ", ui->lineEdit->text()+", ");
                }
            }
        }

        //цикл автозамены в предложениях специфических слов и выражений
        for(auto c: engine->getThirdFaceSpecificCorrect(sex, counting))
        {
            outputText = outputText.replace(QString::fromStdString(c.source), QString::fromStdString(c.target));
            highlight_words.append(QString::fromStdString(c.target));
        }
        ui->txtOutput->setHtml(outputText);

        //Подсветка
        highliter = new Highlighter(highlight_words, ui->txtOutput->document());
    }
    else
    {
        QMessageBox::information(this, "Ошибка", "Отсутствует текст для обработки в поле ввода");
    }
}

void MainWindow::on_action_2_triggered() //Редактор правил
{
    TotallyEditorDialog* ted = new TotallyEditorDialog(this->engine, this);
    ted->exec();
}

void MainWindow::on_action_3_triggered() //Выполнить самообучение на основе известных слов
{
    ui->log->clear();
    if(!ui->txtOutput->toPlainText().isEmpty())
    {
        auto input = engine->getTextObject(ui->txtInput->toPlainText().toStdString());
        auto output = engine->getTextObject(ui->txtOutput->toPlainText().toStdString());
        std::vector<std::string> input_words;
        std::vector<std::string> output_words;
        Sex sex;
        Counting counting;

        //определение единственного и множественного числа
        if(ui->checkBox->isChecked()) counting=Counting::Plural;
            else counting=Counting::Single;

        //мужской или женский пол
        if(ui->radioButton_2->isChecked()) sex = Sex::Male;
            else if(ui->radioButton->isChecked()) sex = Sex::Female;

        for(auto p: input.paragraphs)
        {
            for(auto s: p.sentences)
            { for(auto w: s.words)
                { input_words.push_back(w); } }
        }
        for(auto p: output.paragraphs)
        {
            for(auto s: p.sentences)
            { for(auto w: s.words)
                { output_words.push_back(w); } }
        }

        //Процедура сравнения
        if(input_words.size()==output_words.size())
        {
            for(unsigned long long i=0; i<input_words.size(); i++)
            {
                if(input_words[i]!=output_words[i] && input_words[i]!="я "
                        && input_words[i]!=" я "
                        && input_words[i]!="Я "
                        && input_words[i]!=" я"
                        && input_words[i]!=" Я "
                        && input_words[i]!="я"
                        && input_words[i]!="Я")
                {
                    auto keyword = engine->getThirdFaceRuleByFirstFace(input_words[i], sex, counting);
                    if(keyword=="")
                    {
                        MachineLearnItem* item = new MachineLearnItem(engine, sex, counting, input_words[i], output_words[i]);
                        QListWidgetItem* lw = new QListWidgetItem();
                        ui->log->addItem(lw);
                        lw->setSizeHint(item->sizeHint());
                        ui->log->setItemWidget(lw, item);
                    }
                }
            }
        }
        else
        {
            QMessageBox::information(this, "Обратите внимание", "Ошибка в обучающей выборке! Проверьте ее еще раз внимательно. Количество слов не совпадает.");
        }
    }
    else
    {
        QMessageBox::information(this, "Обратите внимание", "Обучающая выборка пуста.\nНеобходим текст, который должен получиться из поля ввода.\nПрограмма сама определит ключевые слова в выборке");
    }

}

void MainWindow::on_pushButton_clicked() //Ручное добавление корректировочного правила
{
    Sex sex;
    Counting counting;

    //определение единственного и множественного числа
    if(ui->checkBox->isChecked()) counting=Counting::Plural;
        else counting=Counting::Single;

    //мужской или женский пол
    if(ui->radioButton_2->isChecked()) sex = Sex::Male;
        else sex = Sex::Female;

    if(engine->addThirdFaceCorrectSentence(ui->lineEdit_2->text().toStdString(),
                                           ui->lineEdit_3->text().toStdString(),
                                           sex, counting)==true)
    {
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
    }
    else {
        QMessageBox::information(this, "Ошибка добавления правила", "Произошла ошибка добавления правила");
    }
}
