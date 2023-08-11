#include "contents.hpp"
#include "func.hpp"

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
