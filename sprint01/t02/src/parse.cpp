#include "header.h"

static int toint(std::string s, std::string str) {
    int res;
    size_t ind;

    try {
        res = std::stoi(std::string(s), &ind);
        if (s[ind] != '\0')
            throw false;
    }
    catch (...) {
        err2(str);
    }
    return res;
}

void parse(int argc, char *argv[], std::deque<town> &res) {
    for(int i = 1; i < argc; ++i) {
        std::string s;
        std::vector<std::string> v;
        town t;

        s = argv[i];
        split(s, v, ',');

        check_error(s, v);
        if (argc == 2)
            err3();

        t.name = v[0];
        t.stamina = toint(v[1], s);
        t.distance = toint(v[2], s);
        t.position = i - 1;

        res.push_back(t);
    }
}

bool jorney(std::deque<town> res) {
    int storage = 0;

    for (unsigned long i = 0; i < res.size() - 1; ++i) {
        storage += res[i].stamina;
        if (storage >= res[i + 1].distance)
            storage = storage - res[i + 1].distance;
        else
            return false;
    }
    return true;
}

void printjorney(std::deque<town> res) {
    for (auto i : res)
        std::cout << i.position << ". " << i.name << '\n';
}
