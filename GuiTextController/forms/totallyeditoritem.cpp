#include "totallyeditoritem.h"
#include "ui_totallyeditoritem.h"

TotallyEditorItem::TotallyEditorItem(HandlerEngine *engine, bool specific, Sex sex, Counting counting, const std::string& id, const std::string& first,
                                     const std::string& third, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TotallyEditorItem)
{
    ui->setupUi(this);
    this->_id = id;
    this->sex=sex;
    this->counting=counting;
    this->engine=engine;
    this->isSpecific = specific;

    if(this->isSpecific)
    {
        ui->groupBox->setTitle(QString("[СПЕЦИФИКАЦИЯ]: ")+QString::fromStdString(_id));
        ui->pushButton->setVisible(false);

    } else
    {
        ui->groupBox->setTitle(QString("Идентификатор записи: ")+QString::fromStdString(_id));
    }

    ui->lineEdit->setText(QString::fromStdString(first));
    ui->lineEdit_2->setText(QString::fromStdString(third));
    ui->stackedWidget->setCurrentWidget(ui->pgControl);
}

TotallyEditorItem::~TotallyEditorItem()
{
    delete ui;
}

void TotallyEditorItem::on_pushButton_clicked() //Нажатие на изменение записи
{
    bool result = engine->editRuleById(this->_id, ui->lineEdit->text().toStdString(),
                             ui->lineEdit_2->text().toStdString(),
                             this->sex, this->counting);
    ui->stackedWidget->setCurrentWidget(ui->pgMessage);
    if(result==true)
    {
        ui->label_4->setText("Изменено");
        ui->lineEdit->setDisabled(true);
        ui->lineEdit_2->setDisabled(true);
    }
    else {
        ui->label_4->setText("Ошибка");
    }
}

void TotallyEditorItem::on_pushButton_2_clicked() //Удалить правило
{
    bool result = engine->deleteRule(this->_id);
    ui->stackedWidget->setCurrentWidget(ui->pgMessage);
    if(result==true)
    {
        ui->label_4->setText("Удалено");
        ui->lineEdit->setDisabled(true);
        ui->lineEdit_2->setDisabled(true);
    }
    else {
        ui->label_4->setText("Ошибка");
    }
}
