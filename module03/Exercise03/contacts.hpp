#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>
#include <string>

class Contacts {
private:
    std::string name;
    std::string phonenumber;
    std::string email_address;

public:
    Contacts() {}

    Contacts (const Contacts& contact) {
        name = contact.name;
        phonenumber = contact.phonenumber;
        email_address = contact.email_address;
    }

    Contacts &operator = (const Contacts& contact) {
        name = contact.name;
        phonenumber = contact.phonenumber;
        email_address = contact.email_address;

        return *this;
    }

    ~Contacts() {}

    std::string getName() {
        return name;
    }

    std::string getPhonenumber() {
        return phonenumber;
    }

    std::string getEmail_address() {
        return email_address;
    }

    void setName(const std::string& name_) {
        name = name_;
    }

    void setPhonenumber(const std::string& phonenumber_) {
        phonenumber = phonenumber_;
    }

    void setEmail_address(const std::string& email_address_) {
        email_address = email_address_;
    }
};

#endif // CONTACTS_HPP
