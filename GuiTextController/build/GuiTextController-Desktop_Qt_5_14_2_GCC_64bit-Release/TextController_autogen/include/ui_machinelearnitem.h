/********************************************************************************
** Form generated from reading UI file 'machinelearnitem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MACHINELEARNITEM_H
#define UI_MACHINELEARNITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MachineLearnItem
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *pgButton;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label_5;
    QWidget *pgComplete;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QWidget *pgError;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lbErrorText;

    void setupUi(QWidget *MachineLearnItem)
    {
        if (MachineLearnItem->objectName().isEmpty())
            MachineLearnItem->setObjectName(QString::fromUtf8("MachineLearnItem"));
        MachineLearnItem->resize(1058, 60);
        MachineLearnItem->setMinimumSize(QSize(11, 60));
        MachineLearnItem->setMaximumSize(QSize(16777215, 60));
        gridLayout = new QGridLayout(MachineLearnItem);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 1, -1, 1);
        label_3 = new QLabel(MachineLearnItem);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(50, 40));
        QFont font;
        font.setPointSize(9);
        label_3->setFont(font);
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/iconfinder_34_61498.png")));
        label_3->setScaledContents(true);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(MachineLearnItem);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(18);
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);

        label_2 = new QLabel(MachineLearnItem);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label = new QLabel(MachineLearnItem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(45, 45));
        label->setMaximumSize(QSize(45, 45));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/iconfinder_Mac_Text_Edit_1215418.png")));
        label->setScaledContents(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(MachineLearnItem);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pgButton = new QWidget();
        pgButton->setObjectName(QString::fromUtf8("pgButton"));
        gridLayout_2 = new QGridLayout(pgButton);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(pgButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(166, 29));

        gridLayout_2->addWidget(pushButton, 0, 2, 1, 1);

        lineEdit = new QLineEdit(pgButton);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(280, 0));

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);

        label_5 = new QLabel(pgButton);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(16);
        label_5->setFont(font2);

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        stackedWidget->addWidget(pgButton);
        pgComplete = new QWidget();
        pgComplete->setObjectName(QString::fromUtf8("pgComplete"));
        gridLayout_3 = new QGridLayout(pgComplete);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(pgComplete);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu"));
        font3.setPointSize(17);
        font3.setBold(true);
        font3.setWeight(75);
        label_6->setFont(font3);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_6, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        stackedWidget->addWidget(pgComplete);
        pgError = new QWidget();
        pgError->setObjectName(QString::fromUtf8("pgError"));
        gridLayout_4 = new QGridLayout(pgError);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(126, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        lbErrorText = new QLabel(pgError);
        lbErrorText->setObjectName(QString::fromUtf8("lbErrorText"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Ubuntu"));
        font4.setPointSize(13);
        font4.setBold(true);
        font4.setWeight(75);
        lbErrorText->setFont(font4);
        lbErrorText->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        lbErrorText->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lbErrorText, 0, 1, 1, 1);

        stackedWidget->addWidget(pgError);

        gridLayout->addWidget(stackedWidget, 0, 6, 1, 2);


        retranslateUi(MachineLearnItem);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MachineLearnItem);
    } // setupUi

    void retranslateUi(QWidget *MachineLearnItem)
    {
        MachineLearnItem->setWindowTitle(QCoreApplication::translate("MachineLearnItem", "Form", nullptr));
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("MachineLearnItem", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MachineLearnItem", "TextLabel", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("MachineLearnItem", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262 \320\261\320\260\320\267\321\203 \320\276\320\261\321\203\321\207\320\265\320\275\320\270\321\217", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MachineLearnItem", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\262\320\276\320\271 \320\262\320\260\321\200\320\270\320\260\320\275\321\202 \320\264\320\273\321\217 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\262 \320\261\320\260\320\267\321\203", nullptr));
        label_5->setText(QCoreApplication::translate("MachineLearnItem", "\320\270\320\273\320\270...", nullptr));
        label_6->setText(QCoreApplication::translate("MachineLearnItem", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\276", nullptr));
        lbErrorText->setText(QCoreApplication::translate("MachineLearnItem", "\320\236\321\210\320\270\320\261\320\272\320\260 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\277\321\200\320\260\320\262\320\270\320\273\320\260 \320\262 \320\261\320\260\320\267\321\203 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MachineLearnItem: public Ui_MachineLearnItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MACHINELEARNITEM_H
