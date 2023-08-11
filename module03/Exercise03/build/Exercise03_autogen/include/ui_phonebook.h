/********************************************************************************
** Form generated from reading UI file 'phonebook.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHONEBOOK_H
#define UI_PHONEBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Phonebook
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Phonebook)
    {
        if (Phonebook->objectName().isEmpty())
            Phonebook->setObjectName(QString::fromUtf8("Phonebook"));
        Phonebook->resize(510, 413);
        centralwidget = new QWidget(Phonebook);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        Phonebook->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Phonebook);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 510, 22));
        Phonebook->setMenuBar(menubar);
        statusbar = new QStatusBar(Phonebook);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Phonebook->setStatusBar(statusbar);

        retranslateUi(Phonebook);

        QMetaObject::connectSlotsByName(Phonebook);
    } // setupUi

    void retranslateUi(QMainWindow *Phonebook)
    {
        Phonebook->setWindowTitle(QCoreApplication::translate("Phonebook", "Phonebook", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Phonebook", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Phonebook", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("Phonebook", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Phonebook", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Phonebook: public Ui_Phonebook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONEBOOK_H
