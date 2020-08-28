#include "src/header.h"

int main() {
    std::list<Rabbit> population;

    addRabbits(population, 10);
    printpopulation(population);

    while (population.size() <= 1000 &&  population.size() > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        addAge(population);
        clean(population);

        int newBorn = 0;
        countNewborn(population, newBorn);
        addRabbits(population, newBorn);

        turnVampires(population);

        // printlist(population);
        printpopulation(population);
    }
    return 0;
}
