#include <iostream>
#include "castSpells.h"

int main() {
    float d = 123.25;

    std::cout << castFloatToInt(d)
              << ' ' << typeid(d).name()
              << ' ' << typeid(castFloatToInt(d)).name();
    return 0;
}
