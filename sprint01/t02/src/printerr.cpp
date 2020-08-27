#include "header.h"

void err1() {
    std::cerr << "usage: ./visitAll [[name,stamina,distance] ...]\n";
    exit(EXIT_FAILURE);
}
void err2(std::string s) {
    std::cerr << "Argument " << s << " is not valid\n";
    exit(EXIT_FAILURE);
}
void err3() {
    std::cerr << "Mission: Impossible\n";
    exit(EXIT_FAILURE);
}
