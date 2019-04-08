/********************************************************************************
** Form generated from reading UI file 'chatbox.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATBOX_H
#define UI_CHATBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatBox
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_3;
    QPushButton *file_attach;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChatBox)
    {
        if (ChatBox->objectName().isEmpty())
            ChatBox->setObjectName(QString::fromUtf8("ChatBox"));
        ChatBox->resize(639, 459);
        centralWidget = new QWidget(ChatBox);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 601, 381));
        groupBox->setStyleSheet(QString::fromUtf8("background-color:rgb(97, 113, 255)"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(12, 340, 411, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255)"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(490, 340, 101, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color : rgb(255, 234, 129)"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 70, 561, 31));
        label->setStyleSheet(QString::fromUtf8("background-color : rgb(117, 212, 255)"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 110, 561, 31));
        label_2->setStyleSheet(QString::fromUtf8("background-color : rgb(117, 212, 255)"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 150, 561, 31));
        label_3->setStyleSheet(QString::fromUtf8("background-color : rgb(117, 212, 255)"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 190, 561, 31));
        label_4->setStyleSheet(QString::fromUtf8("background-color : rgb(117, 212, 255)"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 230, 561, 31));
        label_5->setStyleSheet(QString::fromUtf8("background-color : rgb(117, 212, 255)"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 270, 561, 31));
        label_6->setStyleSheet(QString::fromUtf8("background-color : rgb(117, 212, 255)"));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 30, 75, 23));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0)"));
        file_attach = new QPushButton(groupBox);
        file_attach->setObjectName(QString::fromUtf8("file_attach"));
        file_attach->setGeometry(QRect(430, 340, 61, 31));
        ChatBox->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChatBox);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 639, 21));
        ChatBox->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChatBox);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ChatBox->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ChatBox);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ChatBox->setStatusBar(statusBar);

        retranslateUi(ChatBox);

        QMetaObject::connectSlotsByName(ChatBox);
    } // setupUi

    void retranslateUi(QMainWindow *ChatBox)
    {
        ChatBox->setWindowTitle(QApplication::translate("ChatBox", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("ChatBox", "GroupBox", nullptr));
        pushButton->setText(QApplication::translate("ChatBox", "Send", nullptr));
        label->setText(QApplication::translate("ChatBox", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("ChatBox", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("ChatBox", "TextLabel", nullptr));
        label_4->setText(QApplication::translate("ChatBox", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("ChatBox", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("ChatBox", "TextLabel", nullptr));
        pushButton_3->setText(QApplication::translate("ChatBox", "PushButton", nullptr));
        file_attach->setText(QApplication::translate("ChatBox", "Attach", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatBox: public Ui_ChatBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOX_H
