#include "draugr.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./draugr [shoutNumber]\n";
        return EXIT_FAILURE;
    }

    std::string input = std::string(argv[1]);
    std::regex r(R"lit(\s*([0-8])\s*)lit");
    std::smatch match;

    try {
        Draugr draugr;
        std::regex_match(input, match, r);
        draugr.shoutPhrase(std::stoi(match[1]));
    }
    catch(...) {
        std::cerr << "Invalid shoutNumber\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
