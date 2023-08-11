#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QMainWindow>
#include <QtWidgets>
#include <QList>
#include <QDebug>
#include <iostream>
#include <map>
#include <string>


QT_BEGIN_NAMESPACE
namespace Ui { 
    class Phonebook;
}
QT_END_NAMESPACE

class Phonebook : public QWidget {
    Q_OBJECT

public:
    Phonebook(QWidget *parent = nullptr);

    void add();
    void remove();
    void search();
    void clear();
    void next();
    void save();
    void load();

private:
    QLineEdit *nameLine;
    QLineEdit *contactLine;
    QTextEdit *addressText;
    QPushButton *addbutton;
    QPushButton *removebutton;
    QPushButton *searchbutton;
    QPushButton *clearbutton;
    QPushButton *nextbutton;
    QPushButton *savebutton;
    QPushButton *loadbutton;    
    QMap<QString, QList<QString>> contact_list;
};

#endif // PHONEBOOK_H
