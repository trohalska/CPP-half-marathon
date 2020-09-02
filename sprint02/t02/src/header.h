#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <regex>

void handle_cin(std::map<std::string, std::string>& lib);
void fileToMap(std::map<std::string, std::string>& lib, const std::string& b);
void add(std::map<std::string, std::string>& lib, const std::string& b);
void remove(std::map<std::string, std::string>& lib, const std::string& b);
void read(const std::map<std::string, std::string>& lib, const std::string& b);
void list(const std::map<std::string, std::string>& lib);