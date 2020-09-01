#include "src/header.h"

int main(int argc, char *argv[]) {
    if (argc < 2)
        err1();

    std::deque<town> res;
    unsigned long i = 0;
    parse(argc, argv, res);

    for (; i < res.size(); ++i) {
        if (jorney(res)) {
            printjorney(res);
            break;
        } else {
            std::rotate(res.begin(), res.begin() + 1, res.end());
        }
    }
    if (i == res.size())
        err3();

    return 0;
}
