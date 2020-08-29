#include <iostream>
#include <string>
#include <vector>

struct Student {
    int age;
    std::string name;

    Student(int _age = 0, std::string _name = "noname") { // constructor
        age = _age;
        name = _name;
        std::cout << "Come to University: ";
        print();
    }
    // void init(int _age, std::string _name) {
    //     this->age = _age;
    //     this->name = _name;
    // }
    void aging() {
        age++;
        std::cout << "I'm " << name << ", i'm " << age << " years old.\n";
    }
    void print() const {
        std::cout << name << " - " << age << std::endl;
    }
    ~Student() {  // destructor
        std::cout << "Leave from University: ";
        print();
    }
};


int main() {
    Student a(17, "Vasya"), s;
    {
        Student b(18, "Petya");
        b.aging();
    }
    {
        Student c(15, "Masha");
    }
    a.aging();
    return 0;
}