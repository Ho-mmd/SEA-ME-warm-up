#include <iostream>
#include <string>
#include <list>
#include <map>

class contents {
    public:
        std::string PNumber;
        std::string Name;
        std::string Nickname;
        char Bookmark;
        int index;
};

class func {
    public:
        void ADD(std::map<std::string, contents>& book);
        void SEARCH(std::map<std::string, contents>& book);
        void REMOVE(std::map<std::string, contents>& book);
        void BOOKMARK(std::map<std::string, contents>& book);
        void EXIT();
};

void func::ADD(std::map<std::string, contents>& book) {
    contents content;
    int size = book.size();
    int index = 1;
    int flag = 1;

    std::cout << "Name - Pnumber - Nickname" << std::endl;
    std::cin >> content.Name >> content.PNumber >> content.Nickname;
    content.Bookmark = '0';

    for(int i = 0; i < content.PNumber.size(); i++) {
        if(48 > (int)content.PNumber[i] || 57 < (int)content.PNumber[i]) {
            flag = 0;
            std::cout << "Please enter the number!" << std::endl;
            break;
        }
    }

    if(flag == 1) {
        book[content.PNumber] = content;

        for (auto& phone : book) {
            phone.second.index = index;

            index++;
        }
    }
    
    if(size + 1 == book.size())
        std::cout << "Success" << std::endl;
    else
        std::cout << "Fail" << std::endl;
}

void func::SEARCH(std::map<std::string, contents>& book) { 
    int index = 1;
    int chk = 1;
    char de;
    std::string contact;

    if(book.size() == 0)
        std::cout << "Phone Book is empty!" << std::endl;
    else {
        for (const auto& phone : book) {
            std::cout << phone.second.index << ". Phone Number: " << phone.second.PNumber;
            
            index++;

            std::cout << std::endl;
        }

        std::cout << "Choose index: ";
        std::cin >> index;
        getchar();

        if(index > 0 && index <= book.size()) {
            for (auto& phone : book) {
                if(phone.second.index == index) {
                    for (int idx=0; idx<3; idx++)
                    {
                        if (idx == 0)
                            std::cout << "Name: " << phone.second.Name << " / ";
                        else if (idx == 1)
                            std::cout << "Nickname: " << phone.second.Nickname << std::endl;
                        else {
                            std::cout << "Bookmark? [Y/N]" << std::endl;
                            std::cin >> de;

                            if(de == 'Y') {
                                phone.second.Bookmark = '1';
                                std::cout << "Bookmark!" << std::endl;
                            }
                                
                            else if(de == 'N') {
                                phone.second.Bookmark = '0';
                                std::cout << "Un_Bookmark!" << std::endl;
                            } 
                            else
                                std::cout << "Choose Y or N Only!" << std::endl;   
                        }
                    }
                    break;
                }
            }
        }
        else {
            std::cout << "Index isn't found in Phone Book" << std::endl;
        }
    }
}

void func::REMOVE(std::map<std::string, contents>& book) {
    std::string contact;
    int index = 1;
    int chk = book.size();

    std::cout << "Write contact want to remove: ";
    std::cin >> contact;

    book.erase(contact);

    if(chk - 1 == book.size()) {
        for (auto& phone : book) {
        phone.second.index = index;

        index++;
        }
    } else 
        std::cout << "there isn't such contact" << std::endl;
}

void func::BOOKMARK(std::map<std::string, contents>& book) {
    int index = 1;


    if(book.size() == 0)
        std::cout << "Phone Book is empty!" << std::endl;
    else {
        for (auto& phone : book) {
            if(phone.second.Bookmark == '1') {
                std::cout << index << ". " << phone.second.PNumber << std::endl;
                index++;
            }
        } 
    }   
}

void func::EXIT() {
    std::cout << "Shut down!";
}

int main() {

    std::map<std::string, contents> book; 
    func method;
    std::string com;
    
    while(std::cout << "Choose Command(ADD / SEARCH / REMOVE / BOOKMARK / EXIT): ") {
        std::cin.clear();
        std::cin >> com;

        if(com == "ADD")
            method.ADD(book);
        else if(com == "SEARCH")
            method.SEARCH(book);
        else if(com == "REMOVE")
            method.REMOVE(book);
        else if(com == "BOOKMARK")
            method.BOOKMARK(book);
        else if(com == "EXIT") {
            method.EXIT();
            return 0;
        }
        else {
            std::cout << "Command Error!" << std::endl;
        }
    }
}
