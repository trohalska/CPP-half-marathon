#include "header.h"

static std::string modfname(const std::string& fname) {
    std::stringstream ss;
    ss << "./library/" << fname;
    return ss.str();
}

void fileToMap(std::map<std::string, std::string>& lib, const std::string& b) {
    try {
        std::ifstream fin(modfname(b), std::ios::in);
        if (!fin)
            throw false;

        if (lib.find(b) != lib.end())
            lib.erase(lib.find(b));
        if (fin.peek() == std::ifstream::traits_type::eof())
            lib[b] += "";
        else {
            fin.seekg(0, std::ios::end);
            lib[b].reserve(fin.tellg());
            fin.seekg(0, std::ios::beg);
            lib[b].assign((std::istreambuf_iterator<char>(fin)),
                            std::istreambuf_iterator<char>());
            lib[b] += '\n';
            std::cout << b << " added\n";
        }
        fin.close();
    }
    catch (...) {
        std::cerr << "invalid book\n";
    }
}
