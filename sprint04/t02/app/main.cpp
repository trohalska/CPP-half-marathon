#include "src/dragonborn.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./dragonborn [action]\n";
        return 1;
    }
    try {
        std::map<std::string, Dragonborn::Actions> inputHashTable;
        inputHashTable["shout"] = Dragonborn::Actions::Shout;
        inputHashTable["magic"] = Dragonborn::Actions::Magic;
        inputHashTable["weapon"] = Dragonborn::Actions::Weapon;

        Dragonborn dovakin;
        dovakin.executeAction(inputHashTable.at(argv[1]));
    }
    catch(...) {
        std::cerr << "Invalid action" << std::endl;
        return 1;
    }
    return 0;
}