/********************************************************************************
** Form generated from reading UI file 'chatbox.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATBOX_H
#define UI_CHATBOX_H

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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatBox
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *file_attach;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChatBox)
    {
        if (ChatBox->objectName().isEmpty())
            ChatBox->setObjectName(QStringLiteral("ChatBox"));
        ChatBox->resize(689, 485);
        centralWidget = new QWidget(ChatBox);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setPointSize(14);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QLatin1String("background-color:rgb(239, 239, 239);\n"
"title{font-color:rgb(255, 0, 0)};"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 253)"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QFont font1;
        font1.setFamily(QStringLiteral("Sitka Subheading"));
        font1.setPointSize(11);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255)"));

        horizontalLayout->addWidget(lineEdit);

        file_attach = new QPushButton(groupBox);
        file_attach->setObjectName(QStringLiteral("file_attach"));
        QFont font2;
        font2.setPointSize(10);
        file_attach->setFont(font2);

        horizontalLayout->addWidget(file_attach);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QStringLiteral("background-color : rgb(211, 207, 207)"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(groupBox);

        ChatBox->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChatBox);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 689, 21));
        ChatBox->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChatBox);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ChatBox->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ChatBox);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ChatBox->setStatusBar(statusBar);

        retranslateUi(ChatBox);

        QMetaObject::connectSlotsByName(ChatBox);
    } // setupUi

    void retranslateUi(QMainWindow *ChatBox)
    {
        ChatBox->setWindowTitle(QApplication::translate("ChatBox", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ChatBox", "GroupBox", Q_NULLPTR));
        file_attach->setText(QApplication::translate("ChatBox", "Attach", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ChatBox", "Send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatBox: public Ui_ChatBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOX_H
