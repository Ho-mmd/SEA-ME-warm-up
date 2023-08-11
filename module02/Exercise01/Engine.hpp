#ifndef ENGINE_H
#define ENGINE_H

#include "Part.hpp"

class Engine : public Part {
    public:
        void print() override {
            std::cout << "Engine Part" << std::endl;
        }
};

#endif