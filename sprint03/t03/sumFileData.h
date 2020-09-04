#pragma once
#include <iostream>
#include <iterator>
#include <fstream>

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

// #include <fstream>
// #include <iterator>
// #include <algorithm>
// #include <iostream>
// #include <numeric>
// #include <string>

// template <class T>
// T sumFileData(const std::string& fileName) {
//     std::ifstream file_stream(fileName);
//     T sum = std::accumulate(std::istream_iterator<T>(file_stream), {}, T{0});

//     file_stream.close();
//     return sum;
// }