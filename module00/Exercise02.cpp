#include <iostream>
#include <string>

class Sentence { //Create a class for save the input
    public:
        std::string select; //Save command Up or Down
        std::string str; //Save Input Senetence
};

int main(int argc, char* argv[]) {

    Sentence sen; //Create Class Variable
    int k = 2; //Index for Input Sentences

    sen.select = argv[1]; //Save command Up or Down

    while(argv[k] != NULL) { //Save Sentence until Nullptr is out
        sen.str.append(argv[k]); 
        sen.str += ' ';
        k++;
    }    

    if(sen.select == "up") { //If command is up, Make sentence Capitalize
        for (int i = 0; i < sen.str.size(); i++)
            if(isalpha(sen.str[i]))
                sen.str[i] = toupper(sen.str[i]);
    } else if (sen.select == "down") { //If command is donw, Make sentence small letter
        for (int i = 0; i < sen.str.size(); i++)
            if(isalpha(sen.str[i]))
                sen.str[i] = tolower(sen.str[i]);   
    } else { //If command doesn't include up or down, print error message
        std::cout << "Type Form: ./convert {up / down} {string}";
        return 0;
    }

    std::cout << sen.str << std::endl; //Print output

    return 0;
}