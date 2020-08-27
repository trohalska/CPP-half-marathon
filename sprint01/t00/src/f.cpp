#include "header.h"

static bool myfunction (std::string i, std::string j) { return (i < j); }

void sortAscii(std::vector<std::string> &res, char *argv[]) {
    for (int i = 1; i <= 5; ++i)
        res.push_back(argv[i]);

    std::sort(res.begin(), res.end(), myfunction);
}