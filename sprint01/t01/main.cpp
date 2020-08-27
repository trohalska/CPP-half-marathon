#include "src/header.h"

int main(int argc, char *argv[]) {
    std::vector<std::string> res;

    if (argc != 2) {
        std::cerr << "usage: ./moveAlong [args]\n";
        return 1;
    }

    if (check(argv[1]))
        std::cout << argv[1] << ", move along!\n";
    return 0;
}
