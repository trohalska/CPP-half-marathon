#include "header.h"

// void printlist(std::list<Rabbit> &population) {
//     for (auto i : population) {
//         if (i.gender == Gender::Male)
//             std::cout << '0';
//         else
//             std::cout << '1';
//         std::cout << " " << i.age << ' ' << i.isVampire << '\n';
//     }
// }

// -------------------------------------------------------------------

void addRabbits(std::list<Rabbit> &population, int count) {
    for (int i = 0; i < count; ++i) {
        Rabbit r;
        r.age = 0;
        r.gender = (rand() % 100) < 50 ? Gender::Male : Gender::Female;
        r.isVampire = (rand() % 100) == 1 ? true : false;
        // r.isTrueBornVampire = r.isVampire ? true : false;

        population.push_back(r);
    }
}

void addAge(std::list<Rabbit> &population) {
    std::for_each(population.begin(), population.end(), [](Rabbit &r){ r.age++; });
}

void clean(std::list<Rabbit> &population) {
    std::remove_if(population.begin(), population.end(), [](Rabbit &r)
                   { return(r.isVampire && r.age > 8); });
    std::remove_if(population.begin(), population.end(), [](Rabbit &r)
                   { return(!r.isVampire && r.age > 3); });
}

void countNewborn(std::list<Rabbit> &population, int &newBorn) {
    int maleNoVamp, femaleNoVamp;

    maleNoVamp = std::count_if(population.begin(), population.end(),
                 [](Rabbit &r){return(!r.isVampire && r.gender == Gender::Male);});
    femaleNoVamp = std::count_if(population.begin(), population.end(),
                   [](Rabbit &r){return(!r.isVampire && r.gender == Gender::Female);});
    newBorn = fmin(maleNoVamp, femaleNoVamp);
}

void turnVampires(std::list<Rabbit> &population) {

    int vamp = std::count_if(population.begin(), population.end(),
               [](Rabbit &r){ return(r.isVampire); });
    // int vamp = std::count_if(population.begin(), population.end(),
    //            [](Rabbit &r){ return(r.isTrueBornVampire); });

    while (vamp != 0) {
        auto newVamp = std::find_if_not(population.begin(), population.end(),
                       [](Rabbit &r){ return(r.isVampire); });
        (*newVamp).isVampire = true;
        vamp--;
    }
}

void printpopulation(std::list<Rabbit> &population) {
    int male = 0, female = 0, vamp = 0;

    male = std::count_if(population.begin(), population.end(),
           [](Rabbit &r){ return(r.gender == Gender::Male); });
    female = std::count_if(population.begin(), population.end(),
             [](Rabbit &r){ return(r.gender == Gender::Female); });
    vamp = std::count_if(population.begin(), population.end(),
           [](Rabbit &r){ return(r.isVampire); });

    std::cout << "Males: " << male << std::endl
              << "Females: " << female << std::endl
              << "Vampires: " << vamp << std::endl;
}