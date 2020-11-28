#include "totallyeditordialog.h"
#include "ui_totallyeditordialog.h"
#include "forms/totallyeditoritem.h"
#include "nlohmann/json.hpp"
#include "qdebug.h"


TotallyEditorDialog::TotallyEditorDialog(HandlerEngine *engine, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TotallyEditorDialog)
{
    ui->setupUi(this);
    this->engine = engine;
}

TotallyEditorDialog::~TotallyEditorDialog()
{
    delete ui;
}

void TotallyEditorDialog::on_pushButton_clicked() //Нажатие по кнопке ПОКАЗАТЬ
{
    ui->listWidget->clear();
    Sex sex; Counting counting;
    std::string t_sex, t_counting;
    ui->comboBox_2->currentIndex();


    switch (ui->comboBox->currentIndex()) {
        case 0: sex=Sex::Male; t_sex="male"; break;
        case 1: sex=Sex::Female; t_sex="female"; break;
    }
    switch (ui->comboBox_2->currentIndex()) {
        case 0: counting=Counting::Single; t_counting="single"; break;
        case 1: counting=Counting::Plural; t_counting="plural"; break;
    }

    //Сначала все правила
    for(auto r: engine->getAllRules(sex, counting))
    {
        auto j = nlohmann::json::parse(r);
        TotallyEditorItem* it = new TotallyEditorItem(this->engine, false,
                                                      sex,
                                                      counting,
                                                      j["_id"].get<std::string>(),
                                                      j["first_face"][t_sex][t_counting].get<std::string>(),
                                                      j["third_face"][t_sex][t_counting].get<std::string>());
        QListWidgetItem* lw = new QListWidgetItem();
        ui->listWidget->addItem(lw);
        lw->setSizeHint(it->sizeHint());
        ui->listWidget->setItemWidget(lw, it);
    }

    //потом специфические правила
    for(auto r: engine->getAllSpecificRules(sex, counting))
    {
        auto j = nlohmann::json::parse(r);
        TotallyEditorItem* it = new TotallyEditorItem(this->engine, true,
                                                      sex,
                                                      counting,
                                                      j["_id"].get<std::string>(),
                                                      j[t_sex][t_counting]["source"].get<std::string>(),
                                                      j[t_sex][t_counting]["target"].get<std::string>());
        QListWidgetItem* lw = new QListWidgetItem();
        ui->listWidget->addItem(lw);
        lw->setSizeHint(it->sizeHint());
        ui->listWidget->setItemWidget(lw, it);

    }

}
