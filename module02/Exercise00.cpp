#include <iostream>
#include <memory>

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

class Sports_Car : virtual public Car {
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

class SUV: virtual public Car {
    private:
        int size;

    public:
        SUV (){}

        SUV (const SUV &suv) {
            size = suv.size;
        }

        SUV &operator = (const SUV &suv) {
            size = suv.size;

            return *this;
        }

        ~SUV() {}

        int getSize() {
            return size;
        }

        void setSize(const int &siz) {
            size = siz;
            std::cout << "Update Size!" << std::endl;
        }

        void drive () {
            Car::drive();

            std::cout << "Size: " << size << std::endl;
        }
};

class Sports_SUV: public Sports_Car, public SUV {
    private:
        std::string muffler;

    public:
        Sports_SUV() {}

        Sports_SUV(const Sports_SUV &s_suv) {
            muffler = s_suv.muffler;
        }

        Sports_SUV &operator = (const Sports_SUV &s_suv) {
            muffler = s_suv.muffler;

            return *this;
        }

        ~Sports_SUV() {}

        std::string getMuffler() {
            return muffler;
        }

        void setMuffler(std::string &muf) {
            muffler = muf;
            std::cout << "Update Muffler!" << std::endl;
        }

        void setMake(std::string& mak) { //Set make
            Car::setMake(mak);
        }

        void setModel(std::string& modl) { //Set model
            Car::setModel(modl);
        }

        void setYear(int& yr) { //Set year
            Car::setYear(yr);
        }

        std::string getMake() { //Set make
            return Car::getMake();
        }

        std::string getModel() { //Set model
            return Car::getModel();
        }

        int getYear() { //Set year
            return Car::getYear();
        }

        void drive() {
            Sports_Car::drive();
            SUV::drive();

            std::cout << "Muffler: " << muffler << std::endl;
        }
};

int main() {
    std::unique_ptr<Sports_Car> sports = std::make_unique<Sports_Car>();
    std::unique_ptr<SUV> suv = std::make_unique<SUV>();
    std::unique_ptr<Sports_SUV> ssuv = std::make_unique<Sports_SUV>();
    std::string make, model, muffler;
    int year, topspeed, size, de;

    std::cout << "1. Sports Car\n" << "2. SUV\n" << "3. Sports SUV\n" << "Select: ";
    std::cin >> de;

    if(de == 1) {
        std::cout << "Make: ";
        std::cin >> make;
        sports->setMake(make);

        std::cout << "Model: ";
        std::cin >> model;
        sports->setModel(model);

        std::cout << "Year: ";
        std::cin >> year;
        sports->setYear(year);

        std::cout << "Top Speed: ";
        std::cin >> topspeed;
        sports->setTop_speed(topspeed);
        
        std::cout << std::endl;

        sports->drive();

    } else if(de == 2) {
        std::cout << "Make: ";
        std::cin >> make;
        suv->setMake(make);

        std::cout << "Model: ";
        std::cin >> model;
        suv->setModel(model);

        std::cout << "Year: ";
        std::cin >> year;
        suv->setYear(year);

        std::cout << "Size: ";
        std::cin >> size;
        suv->setSize(size);

        std::cout << std::endl;

        suv->drive();

    } else if(de == 3) {
        std::cout << "Make: ";
        std::cin >> make;
        ssuv->setMake(make);

        std::cout << "Model: ";
        std::cin >> model;
        ssuv->setModel(model);

        std::cout << "Year: ";
        std::cin >> year;
        ssuv->setYear(year);

        std::cout << "Top Speed: ";
        std::cin >> topspeed;
        ssuv->setTop_speed(topspeed);

        std::cout << "Size: ";
        std::cin >> size;
        ssuv->setSize(size);

        std::cout << "Muffler: ";
        std::cin >> muffler;
        ssuv->setMuffler(muffler);

        std::cout << std::endl;

        ssuv->drive();
    } else {
        std::cout << "Wrong index!";
    }
    

    return 0;
}