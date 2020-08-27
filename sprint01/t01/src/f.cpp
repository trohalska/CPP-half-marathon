#include "header.h"

bool check(std::string s) {
    std::vector<std::string> str = {"merser", "emer", "jim"};
    std::string tmp = s;

    for (std::string::size_type i = 0; i < tmp.length(); ++i)
        tmp[i] = std::tolower(tmp[i]);

    for (auto i : str)
        if (tmp == i)
            return true;

    return false;
}