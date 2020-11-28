/********************************************************************************
** Form generated from reading UI file 'totallyeditordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOTALLYEDITORDIALOG_H
#define UI_TOTALLYEDITORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_TotallyEditorDialog
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;

    void setupUi(QDialog *TotallyEditorDialog)
    {
        if (TotallyEditorDialog->objectName().isEmpty())
            TotallyEditorDialog->setObjectName(QString::fromUtf8("TotallyEditorDialog"));
        TotallyEditorDialog->resize(915, 480);
        gridLayout = new QGridLayout(TotallyEditorDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listWidget = new QListWidget(TotallyEditorDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 1, 0, 1, 1);

        groupBox = new QGroupBox(TotallyEditorDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(250, 0));

        gridLayout_2->addWidget(comboBox, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(250, 0));

        gridLayout_2->addWidget(comboBox_2, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(153, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(pushButton, 0, 4, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(TotallyEditorDialog);

        QMetaObject::connectSlotsByName(TotallyEditorDialog);
    } // setupUi

    void retranslateUi(QDialog *TotallyEditorDialog)
    {
        TotallyEditorDialog->setWindowTitle(QCoreApplication::translate("TotallyEditorDialog", "\320\240\321\203\321\207\320\275\320\276\320\265 \321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\272\320\273\321\216\321\207\320\265\320\262\321\213\321\205 \321\201\320\273\320\276\320\262 \320\277\321\200\320\260\320\262\320\270\320\273", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TotallyEditorDialog", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("TotallyEditorDialog", "\320\234\321\203\320\266\321\201\320\272\320\276\320\271 \321\200\320\276\320\264", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("TotallyEditorDialog", "\320\226\320\265\320\275\321\201\320\272\320\270\320\271 \321\200\320\276\320\264", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("TotallyEditorDialog", "\320\225\320\264\320\270\320\275\321\201\321\202\320\262\320\265\320\275\320\275\320\276\320\265 \321\207\320\270\321\201\320\273\320\276", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("TotallyEditorDialog", "\320\234\320\275\320\276\320\266\320\265\321\201\321\202\320\262\320\265\320\275\320\275\320\276\320\265 \321\207\320\270\321\201\320\273\320\276", nullptr));

        pushButton->setText(QCoreApplication::translate("TotallyEditorDialog", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TotallyEditorDialog: public Ui_TotallyEditorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTALLYEDITORDIALOG_H
