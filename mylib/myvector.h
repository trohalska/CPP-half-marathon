#pragma once
#include "mylib.h"

// template <typename T>
// void print2dvector(std::vector<std::vector<T> > v) {
//     for (unsigned long i = 0; i < v.size(); ++i) {
//         for (unsigned long j = 0; j < v[i].size(); ++j)
//             std::cout << v[i][j] << " ";
//         std::cout << std::endl;
//     }
// }
template<typename T>
void printVector(const std::vector<T>& v) {
    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}
template<typename T>
void vectorJoinClean(std::vector<T>& a, std::vector<T>& b) {
    for (auto i : b)
        a.push_back(i);
    b.clear();
}
template<typename T>
void reverseVector(std::vector<T>& a) {
    int n = a.size();
    for (int i = 0; i < n / 2; ++i)
        std::swap(a[i], a[n - 1 - i]);
}
template<typename T>
std::vector<T> reverseVectorCopy(const vector<T>& v) {
    std::vector<T> b;
    for (auto i = v.rbegin(); i != v.rend(); ++i)
        b.push_back(*i);
    return b;
}