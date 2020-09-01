#include "src/header.h"

int main() {
    std::list<Rabbit> population;

    addRabbits(population, 10);
    printpopulation(population);
    std::cout << '\n';

    while (population.size() <= 1000) {
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
        if (population.size() <= 1000)
            std::cout << '\n';
    }
    return 0;
}
