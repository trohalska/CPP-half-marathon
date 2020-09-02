#include <iostream>
#include "src/StormcloakSoldier.h"
#include "src/ImperialSoldier.h"
#include "src/Axe.h"
#include "src/Sword.h"

static int strToInt(std::string s) {
    int res;
    try {
        size_t ind;
        res = std::stoi(std::string(s), &ind);
        if (s[ind] != '\0' || res > 20 || res < 10)
            throw false;
        return res;
    }
    catch (...) {
        std::cerr << "Damage has to be in a range of 10-20 points.\n";
        exit(EXIT_FAILURE);
    }

}
static void initSoldiers(ImperialSoldier& is, StormcloakSoldier& ss, char *argv[]) {
    auto *sword = new Sword(strToInt(argv[1]));
    auto *axe = new Axe(strToInt(argv[2]));
    is.setWeapon(sword);
    ss.setWeapon(axe);
}
static void fight(ImperialSoldier &is, StormcloakSoldier &ss) {
    while (ss.getHealth() > 0 && is.getHealth() > 0) {
        is.attack(ss);
        ss.attack(is);
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    }
}
static void whoIsWon(ImperialSoldier &is, StormcloakSoldier &ss) {
    if (is.getHealth() > 0)
        std::cout << "Imperial has won!\n";
    else
        std::cout << "Stormcloack has won!\n";
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]\n";
        return 1;
    }
    ImperialSoldier is;
    StormcloakSoldier ss;

    initSoldiers(is, ss, argv);
    fight(is, ss);
    whoIsWon(is, ss);

    return 0;
}