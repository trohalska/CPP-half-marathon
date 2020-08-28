#include "src/header.h"

int main(int argc, char *argv[]) {

    check(argc);

    std::forward_list<std::string> f;
    fileToForwardList(argv[1], f);
    changeInside(f);
    forwardListToModFile(argv[1], f);

    return 0;
}
