#include <iostream>
#include "referenceOrPointer.h"

int main() {
    int w = 5;

    int t = 6;
    multiplyByPointer(&t, w);

    int i = 10;
    multiplyByReference(i, w);

    std::cout << t << " " << i << '\n';

    return 0;
}
