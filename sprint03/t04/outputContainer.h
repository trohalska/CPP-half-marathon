#pragma once
#include <iostream>
#include <ostream>

template <typename Container>
void outputContainer(const Container& container) {
    std::ostream_iterator<typename Container::value_type> oit(std::cout, "\n");
    std::copy(container.begin(), container.end(), oit);
}
