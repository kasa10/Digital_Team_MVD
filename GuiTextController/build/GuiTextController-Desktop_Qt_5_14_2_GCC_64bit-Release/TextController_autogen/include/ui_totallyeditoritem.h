/********************************************************************************
** Form generated from reading UI file 'totallyeditoritem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOTALLYEDITORITEM_H
#define UI_TOTALLYEDITORITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TotallyEditorItem
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *pgControl;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton;
    QWidget *pgMessage;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;

    void setupUi(QWidget *TotallyEditorItem)
    {
        if (TotallyEditorItem->objectName().isEmpty())
            TotallyEditorItem->setObjectName(QString::fromUtf8("TotallyEditorItem"));
        TotallyEditorItem->resize(814, 92);
        TotallyEditorItem->setMinimumSize(QSize(0, 92));
        TotallyEditorItem->setMaximumSize(QSize(16777215, 92));
        gridLayout = new QGridLayout(TotallyEditorItem);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(3, 3, 3, 3);
        groupBox = new QGroupBox(TotallyEditorItem);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(193, 125, 17);"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(groupBox);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pgControl = new QWidget();
        pgControl->setObjectName(QString::fromUtf8("pgControl"));
        gridLayout_3 = new QGridLayout(pgControl);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton = new QPushButton(pgControl);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        stackedWidget->addWidget(pgControl);
        pgMessage = new QWidget();
        pgMessage->setObjectName(QString::fromUtf8("pgMessage"));
        gridLayout_4 = new QGridLayout(pgMessage);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_4 = new QLabel(pgMessage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        stackedWidget->addWidget(pgMessage);

        gridLayout_2->addWidget(stackedWidget, 0, 4, 2, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(193, 125, 17);"));

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 3, 2, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        label_3 = new QLabel(TotallyEditorItem);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(70, 70));
        label_3->setMaximumSize(QSize(70, 70));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/iconfinder_Mac_Text_Edit_1215418.png")));
        label_3->setScaledContents(true);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);


        retranslateUi(TotallyEditorItem);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TotallyEditorItem);
    } // setupUi

    void retranslateUi(QWidget *TotallyEditorItem)
    {
        TotallyEditorItem->setWindowTitle(QCoreApplication::translate("TotallyEditorItem", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TotallyEditorItem", "id \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        label->setText(QCoreApplication::translate("TotallyEditorItem", "1-\320\265 \320\273\320\270\321\206\320\276", nullptr));
        pushButton->setText(QCoreApplication::translate("TotallyEditorItem", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("TotallyEditorItem", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("TotallyEditorItem", "3-\320\265 \320\273\320\270\321\206\320\276", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TotallyEditorItem: public Ui_TotallyEditorItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTALLYEDITORITEM_H
