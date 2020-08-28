#include "header.h"

void check(int argc) {
    if (argc != 2) {
        std::cerr << "usage: ./stdAlgoV2 [file_name]\n";
        exit(EXIT_FAILURE);
    }
}

void changeInside(std::forward_list<std::string>& f) {

    f.remove_if([](std::string& x) {
        return (x.find('c') != std::string::npos
            || x.find('b') != std::string::npos
            || x.find('l') != std::string::npos);
    });
    std::for_each(f.begin(), f.end(), [](std::string &x){
        x = x.length() > 10 ? "Long one" : (x = x.length() < 4 ? "Short one" : x);
    });
    f.sort(std::greater<>{});
    f.unique();
}
