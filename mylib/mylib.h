#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

int strToInt(std::string s) {
    int res;
    size_t ind;
    try {
        res = std::stoi(std::string(s), &ind);
        if (s[ind] != '\0')
            throw false;
    }
    catch (...) {
        std::cerr << "Argument " << s << " is not valid\n";
        exit(EXIT_FAILURE);
    }
    return res;
}
template <class Container>
void mysplit(const std::string& str, Container& c, char delim = ' ') {
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        if (token != "")
            c.push_back(token);
    }
}
// print any container, NOT PAIR
template <class Container>
void outputAny(const Container& c) {
    for (auto x : c)
        std::cout << x << " ";
    srd::cout << '\n';
}
// print any container, NOT PAIR
template <typename Container>
void outputContainer(const Container& container) {
    std::ostream_iterator<typename Container::value_type> oit(std::cout, "\n");
    std::copy(container.begin(), container.end(), oit);
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
// for  any container, NOT PAIR
template <class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
    auto p_end = --end;
    while(begin != p_end) {
        if (*(begin++) != *(end--))
            return false;
    }
    return true;
}
/*
* ----------------------------------------------------- FILES
*/

template <class Container, class T>
void fileToContainer(std::string fname, Container& c, T& s) {
    try {
        std::ifstream fin(fname, std::ios::in | std::ios::binary);
        if (!fin || fin.peek() == std::ifstream::traits_type::eof())
            throw false;
        while(fin >> s)
            c.push_back(s);
    }
    catch (...) {
        std::cerr << "error\n";
        exit(EXIT_FAILURE);
    }
}
template <class Container, class T>
void containerToFile(std::string fname, const Container& c, std::string delim = '\n') {
    std::fstream fout(fname, std::fstream::out | std::fstream::binary);
    for (auto x : c)
        fout << x << delim;
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
/*
* ----------------------------------------------------- MAP
*/
// print map
template<typename key, typename val>
void printMap(const std::map<key, val>& map) {
    for (auto [mkey, mval] : map)
        std::cout << mkey << " => " << mval << '\n';
}
// print multimap
template<typename key, typename val>
void printMultimap(const std::multimap<key, val>& map) {
    for (auto [mkey, mval] : map)
        std::cout << mkey << " => " << mval << '\n';
}
// reverse maps items
template<typename key, typename val>
std::map<val, key> reverseMap(const std::map<key, val>& m) {
    std::map<val, key> res;
    for (auto item : m) {
        res[item.second] = item.first;
    }
    return res;
}
/*
* ----------------------------------------------------- VECTOR
*/
// print <vector<vector<T>>
template <typename T>
void print2dvector(std::vector<std::vector<T> > v) {
    for (unsigned long i = 0; i < v.size(); ++i) {
        for (unsigned long j = 0; j < v[i].size(); ++j)
            std::cout << v[i][j] << " ";
        std::cout << std::endl;
    }
}
// concatinates two vectors
template<typename T>
void vectorJoinClean(std::vector<T>& a, std::vector<T>& b) {
    for (auto i : b)
        a.push_back(i);
    b.clear();
}
// reverse vector
template<typename T>
void reverseVector(std::vector<T>& a) {
    int n = a.size();
    for (int i = 0; i < n / 2; ++i)
        std::swap(a[i], a[n - 1 - i]);
}
// returns reverse vector, doesn't change first one
template<typename T>
std::vector<T> reverseVectorCopy(const std::vector<T>& v) {
    std::vector<T> b;
    for (auto i = v.rbegin(); i != v.rend(); ++i)
        b.push_back(*i);
    return b;
}