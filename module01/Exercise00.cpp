#include <iostream>

class Car {
    private:
        std::string name;
        int speed;
    
    public:
        Car(){} //Default Constructor

        Car(const Car &car) { //Copy Constructor
            name = car.name;
            speed = car.speed;
        }

        Car& operator = (const Car& car) { //Copy assignment operator
            name = car.name; 
            speed = car.speed;

            return *this;
        }

        ~Car(){} //Destructor

        std::string getName() {
            return name;
        }

        int getSpeed() {
            return speed;
        }

        void setName(std::string& nam) {
            name = nam;
        }

        void setSpeed(int& sped) {
            speed = sped;
        }
        
};

int main() {
    Car car1, car2;
    std::string name;
    int speed;

    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Speed: ";
    std::cin >> speed;

    car1.setName(name);
    car1.setSpeed(speed);

    std::cout << car1.getName() << " " << car1.getSpeed() << std::endl;
    
    car2 = car1;

    std::cout << car2.getName() << " " << car2.getSpeed() << std::endl;
    
    Car car3(car2);

    std::cout << car3.getName() << " " << car3.getSpeed() << std::endl;

    return 0;
}
