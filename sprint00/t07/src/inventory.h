#pragma once
#include <iostream>
#include <sstream>
#include <vector>

void insert(std::vector<char>& inv, std::string item);
void remove(std::vector<char>& inv, std::string item);
void show(std::vector<char>& inv);
void help();

template <class Container>
void mysplit1(const std::string& str, Container& cont, char delim = ' ') {
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        if (token != "")
            cont.push_back(token);
    }
}