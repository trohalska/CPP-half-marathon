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

void check_error(const std::string& s, const std::vector<std::string> &v) {

    if (v.size() != 3)
        err2(s);
    for (auto i : v)
        if (i[0] == '\0')
            err2(s);
    for (unsigned char x : v[0])
        if (!std::isalpha(x) && x != ' ')
            err2(v[0]);
    for (unsigned char x : v[1])
        if (!std::isdigit(x))
            err2(s);
    for (unsigned char x : v[2])
        if (!std::isdigit(x))
            err2(s);
}
