#pragma once
#include <iostream>
#include <deque>
#include <vector>
#include <sstream>

struct town {
    std::string name;
    int stamina;
    int distance;
    int position;
};

void parse(int args, char *argv[], std::deque<town> &res);
bool jorney(std::deque<town> res);
void printjorney(std::deque<town> res);

void check_error(const std::string& s, const std::vector<std::string> &v);
void err1();
void err2(std::string s);
void err3();

// -------------------------- templates

template <class Container>
void split(const std::string& str, Container& cont, char delim = ' ') {
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}
