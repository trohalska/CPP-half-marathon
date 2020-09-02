#include "header.h"

// інкапсуляція 

class Student {
// private:  // можна не писати
    int age;
    std::string name;
public:
    Student(std::string x, int a) {
        age = a;
        name = x;
    }
    void aging() {
        age++;
        srd::cout << "aging\n";
    }
}

class SelfCounter {
private:
    static int counter;
public:
    SelfCounter() {
        counter++;
    }
    ~SelfCounter() {
        counter--;
    }
    // static int get_counter() {
    //     return counter;
    // }
    static int get_counter();
}
// --------------------
int SelfCounter::counter = 0;
// --------------------
void foo() {
    for (int i = 0; i < 3; ++i)
        SelfCounter b;
}
int main() {
    std::cout << SelfCounter::get_counter();
    SelfCounter x;
    foo();
    std::cout << x.get_counter();
}
// --------------------

// friend

class CarMaster;
class Car {
private:
    int engine;

    friend class CarMaster;  // if friend - class

    friend void CarMaster::repair(Car&);  // if friend - function
}
class CarMaster {
public:
//     void repair(Car& x) {
//         x.engine++;
//     }
     void repair(Car& x);
}
void CarMaster::repair(Car& x) {
    x.engine++;
}