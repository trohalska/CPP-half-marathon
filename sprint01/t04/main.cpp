#include "src/header.h"

int main(int argc, char *argv[]) {

    check(argc);

    std::forward_list<std::string> f;
    fileToForwardList(argv[1], f);
    printAll(f);

    return 0;
}
