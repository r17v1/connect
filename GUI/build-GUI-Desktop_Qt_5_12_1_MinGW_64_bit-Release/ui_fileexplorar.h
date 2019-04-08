/********************************************************************************
** Form generated from reading UI file 'fileexplorar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEEXPLORAR_H
#define UI_FILEEXPLORAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FileExplorar
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QTreeView *treeView;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;
    QPushButton *send_button;
    QPushButton *cancel_button;

    void setupUi(QDialog *FileExplorar)
    {
        if (FileExplorar->objectName().isEmpty())
            FileExplorar->setObjectName(QString::fromUtf8("FileExplorar"));
        FileExplorar->resize(645, 426);
        verticalLayout = new QVBoxLayout(FileExplorar);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        treeView = new QTreeView(FileExplorar);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        horizontalLayout_2->addWidget(treeView);

        listView = new QListView(FileExplorar);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setMinimumSize(QSize(356, 371));

        horizontalLayout_2->addWidget(listView);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        progressBar = new QProgressBar(FileExplorar);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(1);

        horizontalLayout->addWidget(progressBar);

        send_button = new QPushButton(FileExplorar);
        send_button->setObjectName(QString::fromUtf8("send_button"));

        horizontalLayout->addWidget(send_button);

        cancel_button = new QPushButton(FileExplorar);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));

        horizontalLayout->addWidget(cancel_button);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FileExplorar);
        QObject::connect(cancel_button, SIGNAL(clicked()), FileExplorar, SLOT(reject()));

        QMetaObject::connectSlotsByName(FileExplorar);
    } // setupUi

    void retranslateUi(QDialog *FileExplorar)
    {
        FileExplorar->setWindowTitle(QApplication::translate("FileExplorar", "Dialog", nullptr));
        send_button->setText(QApplication::translate("FileExplorar", "Send", nullptr));
        cancel_button->setText(QApplication::translate("FileExplorar", "Cancle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileExplorar: public Ui_FileExplorar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEEXPLORAR_H
