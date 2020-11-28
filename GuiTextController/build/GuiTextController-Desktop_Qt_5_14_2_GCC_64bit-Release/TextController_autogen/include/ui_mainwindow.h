/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QLabel *label_3;
    QListWidget *log;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QCheckBox *checkBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTextEdit *txtInput;
    QLabel *label_2;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTextEdit *txtOutput;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1149, 678);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(183, 31));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/icons/logo.png")));
        label_5->setScaledContents(true);

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        lineEdit_2 = new QLineEdit(groupBox_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_5->addWidget(lineEdit_2, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox_4);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_5->addWidget(lineEdit_3, 0, 2, 1, 1);

        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_5->addWidget(pushButton, 0, 3, 1, 1);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(30, 30));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/iconfinder_34_61498.png")));
        label_3->setScaledContents(true);

        gridLayout_5->addWidget(label_3, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_4, 3, 0, 1, 1);

        log = new QListWidget(centralwidget);
        log->setObjectName(QString::fromUtf8("log"));

        gridLayout_3->addWidget(log, 5, 0, 1, 3);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 6, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 1, 1, 1);

        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_4->addWidget(lineEdit, 0, 2, 1, 1);

        radioButton = new QRadioButton(groupBox_3);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout_4->addWidget(radioButton, 0, 4, 1, 1);

        radioButton_2 = new QRadioButton(groupBox_3);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setChecked(true);

        gridLayout_4->addWidget(radioButton_2, 0, 3, 1, 1);

        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_4->addWidget(checkBox, 0, 5, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 2, 0, 1, 3);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        txtInput = new QTextEdit(groupBox);
        txtInput->setObjectName(QString::fromUtf8("txtInput"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(14);
        txtInput->setFont(font1);

        gridLayout->addWidget(txtInput, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_2, 4, 0, 1, 3);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(183, 31));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/icons/lod.png")));
        label_6->setScaledContents(true);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_6, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        txtOutput = new QTextEdit(groupBox_2);
        txtOutput->setObjectName(QString::fromUtf8("txtOutput"));
        txtOutput->setFont(font1);

        gridLayout_2->addWidget(txtOutput, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 1, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1149, 20));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action);
        menu->addAction(action_3);
        menu_2->addAction(action_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "[SMART-\321\201\320\277\321\200\320\260\320\262\320\272\320\260] \320\236\320\272\320\275\320\276 \320\272\320\276\320\275\320\262\320\265\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \320\273\320\270\321\206\320\260 \320\277\320\276\320\262\320\265\321\201\321\202\320\262\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\265\321\201\321\202\320\270 \320\260\320\262\321\202\320\276\320\267\320\260\320\274\320\265\320\275\321\203 \320\277\320\276 \320\270\320\267\320\262\320\265\321\201\321\202\320\275\321\213\320\274 \320\264\320\260\320\275\320\275\321\213\320\274", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \320\277\321\200\320\260\320\262\320\270\320\273", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \321\201\320\260\320\274\320\276\320\276\320\261\321\203\321\207\320\265\320\275\320\270\320\265 \320\270\320\267 \320\277\320\276\320\273\320\265\320\271 \320\262\320\262\320\276\320\264\320\260", nullptr));
        label_5->setText(QString());
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\240\321\203\321\207\320\275\320\276\320\265 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201\320\277\320\265\321\206\320\270\321\204\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \321\201\320\273\320\276\320\262 \320\270 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\270\320\271", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262 \320\276\320\261\321\203\321\207\320\265\320\275\320\270\320\265", nullptr));
        label_3->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\233\320\270\321\206\320\276 \320\277\320\276\320\262\320\265\321\201\321\202\320\262\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\241\321\203\320\261\321\212\320\265\320\272\321\202 \320\277\320\276\320\262\320\265\321\201\321\202\320\262\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\244.\320\230.\320\236., \320\277\321\200\320\276\321\201\321\202\320\276 \320\270\320\274\321\217, \320\277\321\201\320\265\320\262\320\264\320\276\320\275\320\270\320\274 \320\270 \321\202.\320\264.", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "\320\226\320\265\320\275\321\201\320\272\320\270\320\271 \321\200\320\276\320\264", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "\320\234\321\203\320\266\321\201\320\272\320\276\320\271 \321\200\320\276\320\264", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 \320\274\320\275\320\276\320\266\320\265\321\201\321\202\320\262\320\265\320\275\320\275\320\276\320\265 \321\207\320\270\321\201\320\273\320\276", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202\320\276\320\262\321\213\320\271 \320\262\320\262\320\276\320\264 #1", nullptr));
        txtInput->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        txtInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265\320\270\320\267\320\262\320\265\321\201\321\202\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        label_6->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202\320\276\320\262\321\213\320\271 \320\262\321\213\320\262\320\276\320\264 #2", nullptr));
        txtOutput->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        txtOutput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\320\270 \320\276\320\261\321\203\321\207\320\265\320\275\320\270\321\217", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\273\320\260\320\264\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
