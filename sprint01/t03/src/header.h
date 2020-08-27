#pragma once
#include <iostream>
#include <list>
#include <cmath>        // fmin

#include <cstdlib>      // srand, rand
#include <ctime>        // time

#include <thread>       // sleep_for, sleep_until
#include <chrono>       // nanoseconds, system_clock, seconds

#include "mylib.h"

enum class Gender {
    Male,
    Female
};

struct Rabbit {
    Gender gender;
    bool isVampire;
    int age;
};

void addRabbits(std::list<Rabbit> &population, int count);
void turnVampires(std::list<Rabbit> &population, int count);
void addAge(std::list<Rabbit> &population);
void clean(std::list<Rabbit> &population);
void count(std::list<Rabbit> &population, int &m, int &f, int &v);
void printpopulation(std::list<Rabbit> &population);

void printlist(std::list<Rabbit> &population);
