#pragma once
#include <map>
#include "mylib.h"

template<typename key, typename val>
void printMap(const std::map<key, val>& map) {
    for (auto [mkey, mval] : map)
        std::cout << mkey << " => " << mval << '\n';
}

template<typename key, typename val>
void printMultimap(const std::multimap<key, val>& map) {
    for (auto [mkey, mval] : map)
        std::cout << mkey << " => " << mval << '\n';
}

template<typename key, typename val>
std::map<val, key> reverseMap(const std::map<key, val>& m) {
    std::map<val, key> res;
    for (auto item : m) {
        res[item.second] = item.first;
    }
    return res;
}
