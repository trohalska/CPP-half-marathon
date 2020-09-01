#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

#include <cmath>        // fmin
#include <cstdlib>      // srand, rand
#include <ctime>        // time
#include <thread>       // sleep_for, sleep_until
#include <chrono>       // nanoseconds, system_clock, seconds

enum class Gender {
    Male,
    Female
};

struct Rabbit {
    Gender gender;
    bool isVampire;
    int age;
    // bool isTrueBornVampire;
};

void addRabbits(std::list<Rabbit> &population, int count);
void addAge(std::list<Rabbit> &population);
void clean(std::list<Rabbit> &population);
void countNewborn(std::list<Rabbit> &population, int &m);
void turnVampires(std::list<Rabbit> &population);
void printpopulation(std::list<Rabbit> &population);

// void printlist(std::list<Rabbit> &population);
