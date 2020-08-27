#include "src/header.h"

int main(int argc, char *argv[]) {
    std::deque<town> res;
    unsigned long i = 0;

    parse(argc, argv, res);

    for (; i < res.size(); ++i) {
        if (jorney(res)) {
            printjorney(res);
            break;
        } else {
            replasetowns(res);
        }
    }
    if (i == res.size())
        err3();

    return 0;
}
