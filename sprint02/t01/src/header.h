#pragma once
#include <iostream>
#include <forward_list>
#include <set>
#include <fstream>
#include <sstream>
#include <regex>

// #include "mylib.h"

void fileToSet(std::string fname, std::multiset<std::string>& f);
void setToModFile(std::string fname, const std::multiset<std::string>& f);