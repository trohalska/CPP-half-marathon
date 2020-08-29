#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>

// #include "../../../mylib/mylib.h"

std::vector<std::string> fileToVector(std::string fname);
void parseLib(std::multimap<std::string, std::string>& lib, std::string fname);
void printLib(const std::multimap<std::string, std::string>& lib);