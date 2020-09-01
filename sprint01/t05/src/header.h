#pragma once
#include <iostream>
#include <forward_list>
#include <fstream>
#include <sstream>

void check(int argc);
void fileToForwardList(std::string fname, std::forward_list<std::string>& f);
void changeInside(std::forward_list<std::string>& f);
void forwardListToModFile(std::string fname, const std::forward_list<std::string>& f);