#pragma once
#include <iostream>

template <class Container>
void outputAny(const Container& c) {
    for (auto x : c)
        std::cout << x << std::endl;
}
