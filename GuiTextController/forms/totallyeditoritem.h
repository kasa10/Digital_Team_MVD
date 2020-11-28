#ifndef TOTALLYEDITORITEM_H
#define TOTALLYEDITORITEM_H

#include <QWidget>
#include "handlerengine.h"

namespace Ui {
class TotallyEditorItem;
}

class TotallyEditorItem : public QWidget
{
    Q_OBJECT

public:
    explicit TotallyEditorItem(HandlerEngine* engine, bool specific, Sex sex, Counting counting, const std::string& id, const std::string& first,
                               const std::string& third, QWidget *parent = nullptr);
    ~TotallyEditorItem();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TotallyEditorItem *ui;
    std::string _id;
    Sex sex;
    Counting counting;
    bool isSpecific;
    HandlerEngine* engine;
};

#endif // TOTALLYEDITORITEM_H
