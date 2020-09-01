#include "src/header.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "usage: ./moveAlong [args]\n";
        return 1;
    }
    std::vector<std::string> res;

    for ( int i = 1; argv[i]; ++i)
        res.push_back(argv[i]);

    for (auto x : res)
        if (check(x))
            std::cout << x << ", move along!\n";
    return 0;
}
