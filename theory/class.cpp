#include "header.h"

/*
 *-------------------------------------------------- інкапсуляція
 */

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
        std::cout << "aging\n";
    }
};

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
};
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
/*
 *-------------------------------------------------- friend
 */
class CarMaster;
class Car {
private:
    int engine;

    friend class CarMaster;  // if friend - class

    friend void CarMaster::repair(Car&);  // if friend - function
};
class CarMaster {
public:
//     void repair(Car& x) {
//         x.engine++;
//     }
     void repair(Car& x);
};
void CarMaster::repair(Car& x) {
    x.engine++;
}

/*
 *-------------------------------------------------- наследование
 */
class Base {
    public:
        void b_pub() {}
    private:
        void b_priv() {}
    protected:
        void b_prot() {}
};
/*  Base b;
 *  b.b_pub() мы можем использовать
 */
class Derivative : Base {  // === class Derivative : private Base {
public:
    void d_pub() {
        b_pub();
        b_prot();
    }
};
/*  ПО УМОЛЧАНИЮ наследование происходит приватно PRIVATE
 *  теперь все методы и данные родителя извне становятся недоступные.
 *  из доступа совсем исчезает раздел private родителя
 *  наследник Derivative вообще ничего не сможет использовать, поскольку
 *  наследование приватное ((
 *
 *  Base b;
 *  Derivative d;
 *  d.b_pub() мы можем использовать
 */

class Derivative: protected Base {
};
/*  все, что было public и protected, становиться protected
 *  и доступным для наследников, но недоступными извне.
 */

class Derivative: public Base {
};
/*  публичное наследование, все гуд, секция public доступна извне.
 *  единственное - наследник определяется как предок (те же переменные и методы)
 */
void foo(Base& x) {
    x.b_pub();
}
Base b;
foo(b);
Derivative d;
foo(d);

// --------------------
class Student {
public:
    Student(std::string x, int a)
    { age = a; name = x; }
    void aging()
    { age++; std::cout << "aging\n"; }
protected:
    int age;
    std::string name;
}; // теперь староста сможет доступаться к данным из protected

class ElderStudent:public Student {
public:
    ElderStudent(std::string s, int x, int gId):Student(s,x) {
        groupID = gId;
    }
protected:
    int groupID;
};

/*
 *  единственный способ
 *  позвать конструктор предка - это список инициализации
 *  Student(s,x) - это список инициализации
 *
 *  в своем конструкторе староста использовал конструктор родителя
 *  + добавил себе еще одно значение в свои данные
 */