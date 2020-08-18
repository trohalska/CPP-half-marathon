#include <iostream>
#include "referenceOrPointer.h"

int main() {
    int t = 6;
    int w = 5;
    multiplyByPointer(&t, w);

    int i = 10;
    int& r = i;
    multiplyByReference(r, w);

    return 0;
}
