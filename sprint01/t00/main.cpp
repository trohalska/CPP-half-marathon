#include "src/header.h"

int main(int argc, char *argv[]) {
    if (argc != 6) {
        std::cerr << "usage: ./simpleSort arg1 arg2 arg3 arg4 arg5\n";
        return 1;
    }
    std::array<std::string, 5> res;
    sortAscii(res, argv);
    for (int i = 0; i < 4; ++i)
        std::cout << res[i] << " ";
    std::cout << res[4] << '\n';

    return 0;
}
