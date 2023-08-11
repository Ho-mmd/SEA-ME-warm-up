#ifndef WHEELS_H
#define WHEELS_H

#include "Part.hpp"

class Wheels : public Part {
    public:
        void print() override {
            for(int i = 0; i < 4; i++)
                std::cout << "Wheel Part" << i << std::endl;
        }
};

#endif