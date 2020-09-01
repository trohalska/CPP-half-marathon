#include "header.h"

static bool myfunction(std::string i, std::string j) {
    return (i < j);
}

void sortAscii(std::array<std::string, 5>& res, char *argv[]) {
    for (int i = 1; i <= 5; ++i)
        res[i - 1] = argv[i];

    std::sort(res.begin(), res.end(), myfunction);
}