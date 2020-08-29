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

// static std::string modfname(std::string fname) {
//     std::stringstream ss;
//     int pos = fname.find('.');

//     if (fname.find('.') == std::string::npos)
//         ss << fname << "_mod";
//     else
//         ss << fname.substr(0, pos) << "_mod" << fname.substr(pos, fname.length());
//     return ss.str();
// }

// void setToModFile(std::string fname, const std::multiset<std::string>& f) {
//     std::string newName = modfname(fname);
//     std::fstream fout(newName, std::fstream::out | std::fstream::binary);
//     auto x = f.begin();
//     while (x != f.end()) {
//         std::string w = *x;
//         int count = 1;
//         for (auto y = ++x; y != f.end(); ++y) {
//             if (w == *y)
//                 count++;
//             else
//                 break;
//         }
//         fout << w << ": " << count << std::endl;
//         for (; count > 1; --count)
//             ++x;
//     }
// }
