#include "src/header.h"

static void check(int argc) {
    if (argc != 2) {
        std::cerr << "usage: ./tesLibrary [file_name]\n";
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {

    check(argc);
    std::multimap<std::string, std::string> lib;
    parseLib(lib, argv[1]);
    printLib(lib);

    return 0;
}
