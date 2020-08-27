#pragma once
#include <iostream>
#include <deque>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

#include "header.h"

int strToInt(std::string s);

template <class Container>
void split(const std::string& str, Container& cont, char delim = ' ') {
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

template<typename T>
void printvector(std::vector<T> v) {
    for (unsigned long i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}
