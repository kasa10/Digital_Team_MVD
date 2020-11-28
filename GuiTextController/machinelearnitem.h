#ifndef MACHINELEARNITEM_H
#define MACHINELEARNITEM_H

#include <QWidget>
#include "handlerengine.h"

namespace Ui {
class MachineLearnItem;
}

class MachineLearnItem : public QWidget
{
    Q_OBJECT

public:
    explicit MachineLearnItem(HandlerEngine *engine, Sex sex, Counting counting, std::string source, std::string target, QWidget *parent = nullptr);
    ~MachineLearnItem();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MachineLearnItem *ui;
    std::string m_source;
    std::string m_target;
    Sex m_sex;
    Counting m_counting;
    HandlerEngine* m_engine;
};

#endif // MACHINELEARNITEM_H
