#include "src/header.h"

static void check(int argc) {
    if (argc != 2) {
        std::cerr << "usage: ./uniqueWords [file_name]\n";
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {

    check(argc);

    std::set<std::string> f;
    fileToSet(argv[1], f);
    setToModFile(argv[1], f);

    return 0;
}
