#include "phonebook.hpp"
#include "./ui_phonebook.h"
#include "QMessageBox"


Phonebook::Phonebook(QWidget *parent) :QWidget(parent) {
    QLabel *nameLabel = new QLabel(tr("Name: "));
    nameLine = new QLineEdit;

    QLabel *contactLabel = new QLabel(tr("Contact: "));
    contactLine = new QLineEdit;
    
    QLabel *addressLabel = new QLabel(tr("Email_Address: "));
    addressText = new QTextEdit;

    addbutton = new QPushButton(tr("&Add"));
    addbutton -> show();
    removebutton = new QPushButton(tr("&Remove"));
    removebutton -> show();
    searchbutton = new QPushButton(tr("&Search"));
    searchbutton -> show();
    clearbutton = new QPushButton(tr("&Clear"));
    clearbutton -> show();
    nextbutton = new QPushButton(tr("&Next"));
    nextbutton -> show();
    savebutton = new QPushButton(tr("&Save"));
    savebutton -> show();
    loadbutton = new QPushButton(tr("&Load"));
    loadbutton -> show();


    connect (addbutton, &QPushButton::clicked, this, &Phonebook::add);
    connect (removebutton, &QPushButton::clicked, this, &Phonebook::remove);
    connect (searchbutton, &QPushButton::clicked, this, &Phonebook::search);
    connect (clearbutton, &QPushButton::clicked, this, &Phonebook::clear);
    connect (nextbutton, &QPushButton::clicked, this, &Phonebook::next);
    connect (savebutton, &QPushButton::clicked, this, &Phonebook::save);
    connect (loadbutton, &QPushButton::clicked, this, &Phonebook::load);

    QVBoxLayout *buttonLayout1 = new QVBoxLayout;
    buttonLayout1->addWidget(addbutton, Qt::AlignTop);
    buttonLayout1->addWidget(removebutton);
    buttonLayout1->addWidget(searchbutton);
    buttonLayout1->addWidget(clearbutton);
    buttonLayout1->addStretch();

    QHBoxLayout *buttonLayout2 = new QHBoxLayout;
    buttonLayout1->addWidget(nextbutton);
    buttonLayout1->addWidget(savebutton);
    buttonLayout1->addWidget(loadbutton);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel, 0, 0);
    mainLayout->addWidget(nameLine, 0, 1);
    mainLayout->addWidget(contactLabel, 1, 0);
    mainLayout->addWidget(contactLine, 1, 1);
    mainLayout->addWidget(addressLabel, 2, 0, Qt::AlignTop);
    mainLayout->addWidget(addressText, 2, 1);
    mainLayout->addLayout(buttonLayout1, 1, 2);
    mainLayout->addLayout(buttonLayout2, 2, 1);

    setLayout(mainLayout);
    setWindowTitle(tr("Simple Book"));
}

void Phonebook::add() {
    QList<QString> contactt;
    int chk = contact_list.size();
    int flag = 0;

    QString name = nameLine -> text();
    QString contact = contactLine -> text();
    QString address = addressText -> toPlainText();

    if (name.isEmpty() || contact.isEmpty() || address.isEmpty()) {
        QMessageBox::information(this, tr("Empty Field"),
            tr("Please enter a name, contact and address."));
    } else {
        for(int i = 0; i < contact.size(); i++) {
            if('0' <= contact[i] && contact[i] <= '9') {
                flag = 1;
            }
        }
            
        if(!flag) {
            QMessageBox::information(this, tr("Warning"),
            tr("Not a Number ㅜㅜ"));

        } else {
            contactt.push_back(name);
            contactt.push_back(address);
            contact_list[contact] = contactt;

            if(chk + 1 == contact_list.size()) {
                QMessageBox::information(this, tr("Add Successful"),
                tr("\"%1\" has been added to your address book.").arg(name));
            } else {
                QMessageBox::information(this, tr("Add Unsuccessful"),
                tr("Sorry, \"%1\" is already in your address book.").arg(name));
            }   
        }
    }
}

void Phonebook::remove() {
    QString contact = contactLine->text();

    if(contact_list.find(contact) == contact_list.end()) {
        QMessageBox::information(this, tr("Remove Unsuccessful"),
        tr("contact doesn't exist ㅜㅜ"));
    } else {
        QMap<QString, QList<QString>>::iterator i = contact_list.find(contact);
        contact_list.erase(i);
         QMessageBox::information(this, tr("Remove successful"),
        tr("Remove!! ^^"));
    }
}

void Phonebook::search() {
    QString contact = contactLine->text();

    if(contact_list.find(contact) == contact_list.end()) {
        QMessageBox::information(this, tr("Search Unsuccessful"),
        tr("Unsearched ㅜㅜ"));
    } else {
        QMap<QString, QList<QString>>::iterator i = contact_list.find(contact);
        contactLine -> setText(i.key());
        nameLine -> setText(i.value()[0]); 
        addressText -> setText(i.value()[1]);
    }
}

void Phonebook::clear() {
    nameLine -> setText("Write Name or Select button");
    contactLine -> setText("Write Contact or Select button");
    addressText -> setText("Write Address or Select button");
}

void Phonebook::next() {
    QString contact = contactLine->text();

    QMap<QString, QList<QString>>::iterator i = contact_list.find(contact);

    if(contact_list.size() == 0) {
        QMessageBox::information(this, tr("Warning"),
        tr("Empty! ㅜㅜ"));
    } else {
        if (i != contact_list.end())
        i++;

        if (i == contact_list.end())
            i = contact_list.begin();

        contactLine -> setText(i.key());
        nameLine -> setText(i.value()[0]); 
        addressText -> setText(i.value()[1]);
    } 
}

void Phonebook::save() {
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Phone Book"), "",
        tr("Phone Book (*.txt);;All Files (*)"));

    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_5);
        out << contact_list;
    }
}

void Phonebook::load() {    
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Open Phone Book"), "",
    tr("Phone Book (*.txt);;All Files (*)"));

    if (fileName.isEmpty())
        return;
    else {

        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        contact_list.clear();   // clear existing contacts
        in >> contact_list;

        if (contact_list.isEmpty()) {
            QMessageBox::information(this, tr("No contacts in file"),
                tr("The file you are attempting to open contains no contacts."));
        } else {
            QMap<QString, QList<QString>>::iterator i = contact_list.begin();
            contactLine->setText(i.key());
            nameLine->setText(i.value()[0]);
            addressText->setText(i.value()[1]);
        }
    }
}