#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <memory>
#include "Part.hpp"
#include "Engine.hpp"
#include "Wheels.hpp"
#include "Brakes.hpp"
#include "Battery.hpp"

class Car {
    private:
        std::unique_ptr <Engine> engine_;
        std::unique_ptr <Wheels> wheel_;
        std::unique_ptr <Brakes> brake_;
        std::unique_ptr <Battery> battery_;

    public:
        Car() {
            engine_ = std::make_unique <Engine> ();
            wheel_ = std::make_unique <Wheels> ();
            brake_ = std::make_unique <Brakes> ();
            battery_ = std::make_unique <Battery> ();    
        }

        void printParts() {
            engine_ -> print();
            wheel_ -> print();
            brake_ -> print();
            battery_ -> print();
        }

        ~Car() {}
};

#endif