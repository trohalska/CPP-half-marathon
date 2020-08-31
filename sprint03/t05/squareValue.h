#pragma once
#include <iostream>
#include <ostream>

template<class Container>
void squareValue(Container& container) {
    for (typename Container::iterator it = container.begin(); it != container.end(); ++it) {
        *it *= *it;
    }
    // for (auto& it : container) {
    //     it *= it;
    // }
}
