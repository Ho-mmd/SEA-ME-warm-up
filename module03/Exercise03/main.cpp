#include "phonebook.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    Phonebook phonebook;
    phonebook.show();
    return a.exec();
}
