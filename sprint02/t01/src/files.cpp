#include "header.h"

void fileToSet(std::string fname, std::multiset<std::string>& f) {
    std::regex r("^\\w+[.|,|!|?]{1}$");

    try {
        std::ifstream fin(fname, std::ios::in | std::ios::binary);
        if (!fin)
            throw false;
        std::string s;
        while(fin >> s) {
            s = std::regex_match(s, r) ? s.erase(s.length() - 1) : s;
            f.insert(s);
        }
    }
    catch (...) {
        std::cerr << "error\n";
        exit(EXIT_FAILURE);
    }
}

static std::string modfname(std::string fname) {
    std::stringstream ss;
    int pos = fname.find('.');

    if (fname.find('.') == std::string::npos)
        ss << fname << "_mod";
    else
        ss << fname.substr(0, pos) << "_mod" << fname.substr(pos, fname.length());
    return ss.str();
}

void setToModFile(std::string fname, const std::multiset<std::string>& f) {
    std::string newName = modfname(fname);
    std::fstream fout(newName, std::fstream::out | std::fstream::binary);
    auto x = f.begin();
    while (x != f.end()) {
        std::string w = *x;
        int count = 1;
        for (auto y = ++x; y != f.end(); ++y) {
            if (w == *y)
                count++;
            else
                break;
        }
        fout << w << ": " << count << std::endl;
        for (; count > 1; --count)
            ++x;
    }
}
