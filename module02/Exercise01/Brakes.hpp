#ifndef BRAKES_H
#define BRAKES_H

#include "Part.hpp"

class Brakes : public Part {
    public:
        void print() override {
            for(int i = 0; i < 4; i++)
                std::cout << "Brakes Part" << i << std::endl;
        }
};

#endif