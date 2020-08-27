#include "header.h"

void parse(int argc, char *argv[], std::deque<town> &res) {

    if (argc < 2)
        err1();

    for(int i = 1; argv[i]; ++i) {
        std::string s;
        std::vector<std::string> v;
        town t;

        s = argv[i];
        split(s, v, ',');

        if (v.size() != 3)
            err2(s);
        for (auto i : v)
            if (i[0] == '\0')
                err2(s);

        t.name = v[0];
        t.stamina = toint(v[1], s);
        t.distance = toint(v[2], s);
        t.position = i - 1;

        res.push_back(t);
    }
}

int toint(std::string s, std::string str) {
    int res;
    size_t ind;

    try {
        res = std::stoi(std::string(s), &ind);
        if (s[ind] != '\0')
            throw false;
    }
    catch (...) {
        std::cerr << "Argument " << str << " is not valid\n";
        exit(EXIT_FAILURE);
    }
    return res;
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

void replasetowns(std::deque<town> &res) {
    town tmp = res[0];
    res.pop_front();
    res.push_back(tmp);
}