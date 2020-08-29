#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "outputAny.h"

int main() {
    std::vector<int> x1({1,2,8,6,9,5,4});
    std::set<int> x2 = {9,5,4};
    std::vector<std::string> x3 = {"aa", "bb", "wwwddd"};

    outputAny(x1);
    outputAny(x2);
    outputAny(x3);

    return 0;
}
