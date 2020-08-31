#include <vector>
#include "squareValue.h"


int main() {
    std::vector<int> myvector;
    for (int i=1; i<=10; ++i) myvector.push_back(i);

    squareValue(myvector);
    for (auto x : myvector)
        std::cout << x << ", ";

    return 0;
}
