#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> A = {10,13,15,22,8};

    // iterator 1
    for (std::vector<int>::iterator i = A.begin(); i != A.end(); ++i)
        std::cout << *i << ' ';

    // iterator 2
    for (auto i = A.begin(); i != A.end(); ++i)
        std::cout << *i << ' ';

    // iterator 3
    for (auto i : A)
        std::cout << i << ' ';


    return 0;
}