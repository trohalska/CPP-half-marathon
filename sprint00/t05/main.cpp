#include <iostream>

int main(int argc, char *argv[]) {

    if (5 != argc) {
        std::cerr << "usage:./automaton [name] [level] [health] [stamina]";
        return EXIT_FAILURE;
    }

    int i;
    size_t ind;
    try {
        for (i = 2; i < 5; ++i) {
            if (2 == i) std::stoi(std::string(argv[i]), &ind);
            else if (3 == i) std::stof(std::string(argv[i]), &ind);
            else if (4 == i) std::stod(std::string(argv[i]), &ind);

            if (argv[i][ind] != '\0') throw argv[i];
        }
        std::cout << "Name = " << argv[1]
                << "\nLevel = " << argv[2]
                << "\nHealth = " << argv[3]
                << "\nStamina = " << argv[4] << std::endl;
    }
    catch (...) {
        std::cerr << "Invalid argument: " << argv[i] << std::endl;
        return 1;
    }
    return 0;
}