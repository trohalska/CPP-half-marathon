#pragma once

#include <iostream>
#include <regex>
#include <sstream>
#include <map>


#include <vector>


void calc(const std::smatch& match);


template<typename key, typename val>
void printMap(const std::map<key, val>& map) {
    for (auto [mkey, mval] : map)
        std::cout << mkey << " => " << mval << '\n';
}