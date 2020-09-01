#include "header.h"

bool check(std::string s) {

    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); } );

    if (s.find("mercer") != std::string::npos
        || s.find("emer") != std::string::npos
        || s.find("jim") != std::string::npos)
        return true;

    return false;
}