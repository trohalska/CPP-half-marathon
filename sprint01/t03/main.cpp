#include "src/header.h"

int main() {
    std::list<Rabbit> population;
    int countBornVamp = 0;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    addRabbits(population, 10, countBornVamp);
    printpopulation(population);
    std::cout << '\n';

    while (population.size() <= 1000) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        addAge(population);
        turnVampires(population, countBornVamp);

        int newBorn = 0;
        countNewborn(population, newBorn);
        addRabbits(population, newBorn, countBornVamp);

        clean(population);

        // printlist(population);
        printpopulation(population);
        if (population.size() <= 1000)
            std::cout << '\n';
    }
    return 0;
}
