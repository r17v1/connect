/********************************************************************************
** Form generated from reading UI file 'friendwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDWINDOW_H
#define UI_FRIENDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QPushButton *AddFriendButton;
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
            FriendWindow->setObjectName(QStringLiteral("FriendWindow"));
        FriendWindow->resize(627, 425);
        centralWidget = new QWidget(FriendWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral("background-color : rgb(239, 239, 239)"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        AddFriendButton = new QPushButton(groupBox);
        AddFriendButton->setObjectName(QStringLiteral("AddFriendButton"));

        verticalLayout->addWidget(AddFriendButton);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral("background-color : rgb(255, 255, 255)"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QStringLiteral("background-color : rgb(255, 255, 255)"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QStringLiteral("background-color : rgb(255, 255, 255)"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setStyleSheet(QStringLiteral("background-color : rgb(255, 255, 255)"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setStyleSheet(QStringLiteral("background-color : rgb(255, 255, 255)"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setStyleSheet(QStringLiteral("background-color : rgb(247, 239, 239)"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setStyleSheet(QStringLiteral("background-color : rgb(247, 239, 239)"));

        verticalLayout->addWidget(pushButton_7);


        horizontalLayout->addWidget(groupBox);

        FriendWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FriendWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 627, 21));
        FriendWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FriendWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FriendWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FriendWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FriendWindow->setStatusBar(statusBar);

        retranslateUi(FriendWindow);

        QMetaObject::connectSlotsByName(FriendWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FriendWindow)
    {
        FriendWindow->setWindowTitle(QApplication::translate("FriendWindow", "Friends", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("FriendWindow", "GroupBox", Q_NULLPTR));
        AddFriendButton->setText(QApplication::translate("FriendWindow", "Add Contact", Q_NULLPTR));
        pushButton->setText(QApplication::translate("FriendWindow", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("FriendWindow", "PushButton", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("FriendWindow", "PushButton", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("FriendWindow", "PushButton", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("FriendWindow", "PushButton", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("FriendWindow", "PushButton", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("FriendWindow", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FriendWindow: public Ui_FriendWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDWINDOW_H
