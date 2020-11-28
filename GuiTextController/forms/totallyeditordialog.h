#ifndef TOTALLYEDITORDIALOG_H
#define TOTALLYEDITORDIALOG_H

#include <QDialog>
#include "handlerengine.h"

namespace Ui {
class TotallyEditorDialog;
}

class TotallyEditorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TotallyEditorDialog(HandlerEngine* engine, QWidget *parent = nullptr);
    ~TotallyEditorDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TotallyEditorDialog *ui;
    HandlerEngine* engine;
};

#endif // TOTALLYEDITORDIALOG_H
