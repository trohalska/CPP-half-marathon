#include "src/header.h"

int main() {
    std::list<Rabbit> population;

    addRabbits(population, 10);

    while (population.size() <= 50 &&  population.size() > 0) { // 1000
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        addAge(population);
        clean(population);

        int maleNoVamp = 0, femaleNoVamp = 0, vampire = 0;
        count(population, maleNoVamp, femaleNoVamp, vampire);

        addRabbits(population, fmin(maleNoVamp, femaleNoVamp));
        turnVampires(population, vampire);

        // printlist(population);
        printpopulation(population);
    }
    return 0;
}
