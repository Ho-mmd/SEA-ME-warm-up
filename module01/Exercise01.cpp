#include <iostream>

class Car {
    private:
        std::string make;
        std::string model;
        int year;

    public:
        Car() {} //Default Constructor

        Car(const Car& car) { //Copy Constructor
            make = car.make;
            model = car.model;
            year = car.year;
        }

        Car& operator = (const Car& car) { //Copy Assignment Operator
            make = car.make;
            model = car.model;
            year = car.year;

            return *this;
        }

        ~Car() {} //Destructor

        void drive() {
            std::cout << "Make: " << make << std::endl;
            std::cout << "Model: " << model << std::endl;
            std::cout << "Year: " << year << std::endl;
        }

        std::string getMake() { //Return make
            return make;
        }

        std::string getModel() { //Return model
            return model;
        }

        int getYear() { //Return year
            return year;
        }

        void setMake(std::string& mak) { //Set make
            make = mak;
            std::cout << "Update Make!" << std::endl;
        }

        void setModel(std::string& modl) { //Set model
            model = modl;
            std::cout << "Update Model!" << std::endl;
        }

        void setYear(int& yr) { //Set year
            year = yr;
            std::cout << "Update Year!" << std::endl;
        }
};

class Sports_Car : public Car {
    private:
        int top_speed;

    public:
        Sports_Car() {}

        Sports_Car(const Sports_Car& sportscar) {
            top_speed = sportscar.top_speed;
        }

        Sports_Car& operator = (const Sports_Car& sportscar) {
            top_speed = sportscar.top_speed;

            return *this;
        }

        ~Sports_Car() {}

        void setTop_speed (const int &top_sped) {
            top_speed = top_sped;
            std::cout << "Update Top_Speed!" << std::endl;
        }

        int getTop_speed () {
            return top_speed;
        }

        void drive() {
            Car::drive();
            std::cout << "Top Speed: " << top_speed << std::endl; 
        }
};

int main() {
    Sports_Car sports;
    std::string make, model;
    int year, topspeed;

    std::cout << "Make: ";
    std::cin >> make;
    sports.setMake(make);

    std::cout << "Model: ";
    std::cin >> model;
    sports.setModel(model);

    std::cout << "Year: ";
    std::cin >> year;
    sports.setYear(year);

    std::cout << "Top Speed: ";
    std::cin >> topspeed;
    sports.setTop_speed(topspeed);
    
    std::cout << std::endl;

    sports.drive();

    return 0;
}