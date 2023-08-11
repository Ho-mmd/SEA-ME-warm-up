#ifndef BATTERY_H
#define BATTERY_H

#include "Part.hpp"

class Battery : public Part {
    public:
        void print() override {
            std::cout << "Battery Part" << std::endl;
        }
};

#endif