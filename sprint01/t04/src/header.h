#pragma once
#include <iostream>
#include<forward_list>
#include <fstream>

// #include "mylib.h"

void check(int argc);
void fileToForwardList(std::string fname, std::forward_list<std::string>& f);
void printAll(const std::forward_list<std::string>& f);