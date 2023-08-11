#ifndef FUNC_H
#define FUNC_H

#include <string>
#include <list>
#include <map>
#include "contents.hpp"

class func {
    public:
        void ADD(std::map<std::string, contents>& book);
        void SEARCH(std::map<std::string, contents>& book);
        void REMOVE(std::map<std::string, contents>& book);
        void BOOKMARK(std::map<std::string, contents>& book);
        void EXIT();
};

#endif