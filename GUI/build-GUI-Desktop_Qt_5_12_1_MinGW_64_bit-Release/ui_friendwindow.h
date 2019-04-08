/********************************************************************************
** Form generated from reading UI file 'friendwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDWINDOW_H
#define UI_FRIENDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FriendWindow)
    {
        if (FriendWindow->objectName().isEmpty())
            FriendWindow->setObjectName(QString::fromUtf8("FriendWindow"));
        FriendWindow->resize(627, 386);
        centralWidget = new QWidget(FriendWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 571, 311));
        groupBox->setStyleSheet(QString::fromUtf8("background-color : rgb(90, 98, 255)"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 541, 51));
        pushButton->setStyleSheet(QString::fromUtf8("background-color : rgb(85, 255, 255)"));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 70, 541, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color : rgb(85, 255, 255)"));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 120, 541, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color : rgb(85, 255, 255)"));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 170, 541, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color : rgb(85, 255, 255)"));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 220, 541, 51));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color : rgb(85, 255, 255)"));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(490, 280, 71, 21));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color : rgb(255, 56, 21)"));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 280, 71, 21));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color : rgb(255, 56, 21)"));
        FriendWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FriendWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 627, 26));
        FriendWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FriendWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        FriendWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FriendWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FriendWindow->setStatusBar(statusBar);

        retranslateUi(FriendWindow);

        QMetaObject::connectSlotsByName(FriendWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FriendWindow)
    {
        FriendWindow->setWindowTitle(QApplication::translate("FriendWindow", "Friends", nullptr));
        groupBox->setTitle(QApplication::translate("FriendWindow", "GroupBox", nullptr));
        pushButton->setText(QApplication::translate("FriendWindow", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("FriendWindow", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("FriendWindow", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("FriendWindow", "PushButton", nullptr));
        pushButton_5->setText(QApplication::translate("FriendWindow", "PushButton", nullptr));
        pushButton_6->setText(QApplication::translate("FriendWindow", "PushButton", nullptr));
        pushButton_7->setText(QApplication::translate("FriendWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendWindow: public Ui_FriendWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDWINDOW_H
