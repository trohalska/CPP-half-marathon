#include "header.h"

void check(int argc) {
    if (argc != 2) {
        std::cerr << "usage: ./stdAlgoV1 [file_name]\n";
        exit(EXIT_FAILURE);
    }
}

bool exist(std::string PATH) {
    std::ifstream fin;
    fin.open(PATH.c_str());
    return bool(fin);
}

void fileToForwardList(std::string fname, std::forward_list<std::string>& f) {

    try {
        std::ifstream fin(fname, std::ios::in | std::ios::binary);
        if (!fin || fin.peek() == std::ifstream::traits_type::eof())
            throw false;
        std::string s;
        while(fin >> s)
            f.push_front(s);
    }
    catch (...) {
        std::cerr << "error\n";
        exit(EXIT_FAILURE);
    }
}

void printAll(const std::forward_list<std::string>& f) {
    int size = 0,
        mel = 0;
    std::string rich = "false\n",
                len = "true\n",
                vel = "true\n";

    for (auto x : f) {
        size++;
        if (x.find("rich") != std::string::npos)
            rich = "true\n";
        if (x.length() == 15)
            len = "false\n";
        if (x.find("vel") != x.length() - 3)
            vel = "false\n";
        if (x.find("mel") == std::string::npos)
            mel++;
    }
    std::cout << "size: " << size << std::endl
              << "contains 'rich': " << rich
              << "none of lengths is 15: " << len
              << "all end with 'vel': " << vel
              << "not contains 'mel': " << mel << std::endl;
}
