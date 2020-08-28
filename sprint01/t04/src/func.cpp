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
        if (!fin)
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

    for (auto i = f.begin(); i != f.end(); ++i) {
        size++;
        if ((*i).find("rich") != std::string::npos)
            rich = "true\n";
        if ((*i).length() == 15)
            len = "false\n";
        if ((*i).find("vel") != (*i).length() - 3)
            vel = "false\n";
        if ((*i).find("mel") == std::string::npos)
            mel++;
    }
    std::cout << "size: " << size << std::endl
              << "contains 'rich': " << rich
              << "none of lengths is 15: " << len
              << "all end with 'vel': " << vel
              << "not contains 'mel': " << mel << std::endl;
}
