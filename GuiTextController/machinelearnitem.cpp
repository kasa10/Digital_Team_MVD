#include "machinelearnitem.h"
#include "ui_machinelearnitem.h"
#include "qdebug.h"


MachineLearnItem::MachineLearnItem(HandlerEngine* engine, Sex sex, Counting counting, std::string source, std::string target, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MachineLearnItem)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pgButton);
    this->m_engine = engine;
    this->m_source=source;
    this->m_target=target;
    this->m_counting=counting;
    this->m_sex=sex;
    ui->label_2->setText(QString::fromStdString(m_source));
    ui->label_4->setText(QString::fromStdString(m_target));
}

MachineLearnItem::~MachineLearnItem()
{
    delete ui;
}

void MachineLearnItem::on_pushButton_clicked() //Добавить в базу
{
    qDebug() << "Добавление найденного элемента: " << m_source.c_str() << " " << m_target.c_str();
    if(m_engine->addThirdFaceRuleToMachine(m_source, m_target, m_sex, m_counting) ==true)
    {
        ui->stackedWidget->setCurrentWidget(ui->pgComplete);
    }
    else
    {
        ui->stackedWidget->setCurrentWidget(ui->pgError);
        ui->lbErrorText->setText("Ошибка добавления правила в базу данных");
    }
}
