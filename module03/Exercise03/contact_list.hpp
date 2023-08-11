#ifndef CONTACT_LIST_HPP
#define CONTACT_LIST_HPP

#include "contacts.hpp"
#include "phonebook.hpp"
#include <list>
#include <string>

class Contact_List {
private:
    std::list<Contacts> contact_list;

public:
    int add(Contacts& contact) {
        for(auto i = contact_list.begin(); i != contact_list.end(); i++) {
            if(i->getPhonenumber() != contact.getPhonenumber()) {
                std::cout << "Add Failed!" << std::endl;
                return 0;
            }
        }

        contact_list.push_back(contact);
        std::cout << "Add Success!" << std::endl;

        return 1;
    }

    int remove(Contacts& contact) {
        Contacts tmp = search(contact);

        contact_list.remove(tmp);

        return 0;
    }

    Contacts search(Contacts& contact) {
        // for(auto i = contact_list.begin(); i != contact_list.end(); i++) {
        //     if(i->getPhonenumber() == contact.getPhonenumber()) {
        //         std::cout << "Search Success!" << std::endl;
        //         return contact;
        //     }
        // }

        std::cout << "Search Failed!" << std::endl;
    }
};


#endif // CONTACT_LIST_HPP
