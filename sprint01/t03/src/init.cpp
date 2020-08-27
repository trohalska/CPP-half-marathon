#include "header.h"

void printlist(std::list<Rabbit> &population) {
    for (auto i : population) {
        if (i.gender == Gender::Male)
            std::cout << '0';
        else
            std::cout << '1';
        std::cout << " " << i.age << ' ' << i.isVampire << '\n';
    }
}

// -------------------------------------------------------------------

void addRabbits(std::list<Rabbit> &population, int count) {
    for (int i = 0; i < count; ++i) {
        Rabbit r;
        r.age = 0;
        r.gender = (rand() % 100) < 50 ? Gender::Male : Gender::Female;
        r.isVampire = (rand() % 100) == 1 ? true : false;
        population.push_back(r);
    }
}

void turnVampires(std::list<Rabbit> &population, int count) {
    for (auto i = population.begin(); i != population.end(); ++i) {
        if (!(*i).isVampire && count) {
            (*i).isVampire = true;
            count--;
        }
        if (count == 0)
            break;
    }
}

void addAge(std::list<Rabbit> &population) {
    for (auto i = population.begin(); i != population.end(); ++i)
        (*i).age += 1;
}

void clean(std::list<Rabbit> &population) {
    for (auto i = population.begin(); i != population.end(); ++i) {
        if ((*i).isVampire) {
            if ((*i).age > 8)
                population.erase(i);
        }
        else {
            if ((*i).age > 3)
                population.erase(i);
        }
    }
}

void count(std::list<Rabbit> &population, int &m, int &f, int &v) {
    for (auto i = population.begin(); i != population.end(); ++i) {
        if ((*i).isVampire)
            v++;
        else {
            if ((*i).gender == Gender::Male)
                m++;
            else
                f++;
        }
    }
}

void printpopulation(std::list<Rabbit> &population) {
    int male = 0, female = 0, vampire = 0;
    for (auto i = population.begin(); i != population.end(); ++i) {
        if ((*i).gender == Gender::Male)
            male++;
        else
            female++;
        if ((*i).isVampire)
            vampire++;
    }
    std::cout << "Males: " << male << std::endl
              << "Females: " << female << std::endl
              << "Vampires: " << vampire << "\n\n";
}