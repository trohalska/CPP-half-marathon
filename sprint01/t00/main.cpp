#include "src/header.h"

int main(int argc, char *argv[]) {
    std::vector<std::string> res;

    if (argc != 6) {
        std::cerr << "usage: ./simpleSort arg1 arg2 arg3 arg4 arg5\n";
        return 1;
    }
    sortAscii(res, argv);
    printvector((std::vector<std::string>)res);
    return 0;
}
