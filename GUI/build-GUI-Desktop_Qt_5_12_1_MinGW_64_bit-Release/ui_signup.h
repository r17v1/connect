/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_firstname;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_lastname;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_username;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_email;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_password;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_retype_pass;
    QPushButton *pushButton_submit;

    void setupUi(QDialog *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName(QString::fromUtf8("SignUp"));
        SignUp->resize(400, 300);
        groupBox = new QGroupBox(SignUp);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 10, 271, 261));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_firstname = new QLineEdit(groupBox);
        lineEdit_firstname->setObjectName(QString::fromUtf8("lineEdit_firstname"));

        horizontalLayout->addWidget(lineEdit_firstname);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_lastname = new QLineEdit(groupBox);
        lineEdit_lastname->setObjectName(QString::fromUtf8("lineEdit_lastname"));

        horizontalLayout_2->addWidget(lineEdit_lastname);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_username = new QLineEdit(groupBox);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));

        horizontalLayout_3->addWidget(lineEdit_username);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_email = new QLineEdit(groupBox);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));

        horizontalLayout_4->addWidget(lineEdit_email);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_5->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_retype_pass = new QLineEdit(groupBox);
        lineEdit_retype_pass->setObjectName(QString::fromUtf8("lineEdit_retype_pass"));
        lineEdit_retype_pass->setEchoMode(QLineEdit::Password);

        horizontalLayout_6->addWidget(lineEdit_retype_pass);


        verticalLayout->addLayout(horizontalLayout_6);

        pushButton_submit = new QPushButton(groupBox);
        pushButton_submit->setObjectName(QString::fromUtf8("pushButton_submit"));

        verticalLayout->addWidget(pushButton_submit);


        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QDialog *SignUp)
    {
        SignUp->setWindowTitle(QApplication::translate("SignUp", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("SignUp", "Sign Up", nullptr));
        label->setText(QApplication::translate("SignUp", "First Name", nullptr));
        label_2->setText(QApplication::translate("SignUp", "Last Name", nullptr));
        label_3->setText(QApplication::translate("SignUp", "Username", nullptr));
        label_4->setText(QApplication::translate("SignUp", "E-mail", nullptr));
        label_5->setText(QApplication::translate("SignUp", "Password", nullptr));
        label_6->setText(QApplication::translate("SignUp", "ReType Pass", nullptr));
        pushButton_submit->setText(QApplication::translate("SignUp", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
