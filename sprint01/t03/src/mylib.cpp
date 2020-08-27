#include "header.h"

int strToInt(std::string s) {
    int res;
    size_t ind;

    try {
        res = std::stoi(std::string(s), &ind);
        if (s[ind] != '\0')
            throw false;
    }
    catch (...) {
        std::cerr << "Argument " << s << " is not valid\n";
        exit(EXIT_FAILURE);
    }
    return res;
}
