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

static std::smatch getNames(std::string s) {
    std::regex r(R"lit((.+),(.+))lit");
    std::smatch match;

    try {
        if (!std::regex_match(s, match, r))
            throw false;
        return match;
    }
    catch (...) {
        std::cerr << "Invalid names\n";
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4 || argc > 5) {
        std::cerr << "usage: ./draugr [shoutNumber] [name1,name2] [health] [frostResist]\n";
        return EXIT_FAILURE;
    }
    int shoutNum = getShoutNumber(argv[1]);
    std::smatch names = getNames(argv[2]);

    try {
        if (argc == 4) {
            Draugr draugr(std::stod(argv[3])); // third constructor
            draugr.setName(names[1]);
            draugr.shoutPhrase(shoutNum);

            Draugr draugr2 = draugr;
            draugr2.setName(names[2]);
            draugr2.shoutPhrase(shoutNum);
        }
        else if (argc == 5) {
            Draugr draugr(std::stod(argv[3]), std::stoi(argv[4]));
            draugr.setName(names[1]);
            draugr.shoutPhrase(shoutNum);

            Draugr draugr2 = std::move(draugr);
            draugr2.setName(names[2]);
            draugr2.shoutPhrase(shoutNum);
        }
    }
    catch(...) {
        std::cerr << "Error" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
