#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

#include "myvector.h"
#include "mymap.h"

int strToInt(std::string s);

template <class Container>
void mysplit(const std::string& str, Container& cont, char delim = ' ') {
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        if (token != "")
            cont.push_back(token);
    }
}
template <class Container>
void outputAny(const Container& c) {
    for (auto x : c)
        std::cout << x << std::endl;
}
template <class T, class ...Ts>
T sumOfArguments(T t, Ts... args) {
    return t + (args + ...);
}
template <class T1, class T2, class ...Ts>
bool equalsAnyOf(const T1& t1, const T2& t2, const Ts &... ts) {
    return ((t1 == t2) || ... || (t1 == ts));
    // return (((t1 == t2) || (t1 == t3) || ...) || t1 == ts);
}
template <class T>
T sumFileData(const std::string& fileName) {
    T sum = 0;
    std::ifstream file(fileName, std::ios::in);

    std::istream_iterator<T> eos;
    std::istream_iterator<T> iit(file);

    while (iit != eos) {
        sum += *iit;
        ++iit;
    }
    file.close();
    return sum;
}
template <typename Container>
void outputContainer(const Container& container) {
    std::ostream_iterator<typename Container::value_type> oit(std::cout, "\n");
    std::copy(container.begin(), container.end(), oit);
}
template <class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
    auto p_end = --end;
    while(begin != p_end) {
        if (*(begin++) != *(end--))
            return false;
    }
    return true;
}