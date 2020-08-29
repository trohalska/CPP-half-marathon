#include "header.h"

std::vector<std::string> fileToVector(std::string fname) {
    std::vector<std::string> f;

    try {
        std::ifstream fin(fname, std::ios::in);
        if (!fin || fin.peek() == std::ifstream::traits_type::eof())
            throw false;

        std::string s;
        while(std::getline(fin, s)) {
            f.push_back(s);
        }
        fin.close();
        return f;
    }
    catch (...) {
        std::cerr << "error\n";
        exit(EXIT_FAILURE);
    }
}
