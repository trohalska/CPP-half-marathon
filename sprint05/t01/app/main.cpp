#include "src/Draugr.h"
// #include "Draugr.h"

static int getShoutNumber(std::string s) {
    std::regex r(R"lit(\s*([0-8])\s*)lit");
    std::smatch match;

    try {
        std::regex_match(s, match, r);
        return std::stoi(match[1]);
    }
    catch (...) {
        std::cerr << "Invalid shoutNumber\n";
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 4) {
        std::cerr << "usage: ./draugr [shoutNumber] [health] [frostResist]\n";
        return EXIT_FAILURE;
    }
    int shoutNum = getShoutNumber(argv[1]);

    try {
        if (argc == 2) {
            Draugr draugr;
            draugr.shoutPhrase(shoutNum);
        }
        else if (argc == 3) {
            Draugr draugr(std::stod(argv[2]));
            draugr.shoutPhrase(shoutNum);
            Draugr draugr2(std::stoi(argv[2]));
            draugr2.shoutPhrase(shoutNum);
        }
        else if (argc == 4) {
            Draugr draugr(std::stod(argv[2]), std::stoi(argv[3]));
            draugr.shoutPhrase(shoutNum);
        }
    }
    catch(...) {
        std::cerr << "Error" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
