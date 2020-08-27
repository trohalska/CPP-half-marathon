#pragma once
#include "header.h"

template <typename T>
void print2dvector(std::vector<std::vector<T> > v) {
    for (unsigned long i = 0; i < v.size(); ++i) {
        for (unsigned long j = 0; j < v[i].size(); ++j)
            std::cout << v[i][j] << " ";
        std::cout << std::endl;
    }
}

template<typename T>
void printvector(std::vector<T> v) {
    for (unsigned long i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}
