#include "dwemerCalculator.h"

static void matchToMap(std::map<std::string, std::string>& m,
                       const std::smatch& match) {
    m["operand1"] = match[1];
    m["operation"] = match[2];
    m["operand2"] = match[3];
    if (match.size() > 4)
        m["variable"] = match[4];
}

static void checkInt(std::string x, std::string s) {
    size_t ind;
    try {
        int res = std::stoi(std::string(x), &ind);
        // if (x[ind] != '\0')
        //     throw false;
    }
    catch (...) {
        std::cerr << s << " is out of range\n";
    }
}

static void check(std::map<std::string, std::string>& m) {
    static std::map<char, int> var;

    std::regex r("[?+|?-]\\d+");
    std::smatch match;


    try {
        std::map<std::string, std::string>::iterator it = m.begin();

        if (it->second.size() == 1 && std::isalpha(it->second[0])){
            // сверить с архивом
        } else if (std::regex_match(it->second, match, r)) {
            checkInt(it->second, it->first);
        }
        else
            throw false;
    }
    // catch(std::string x) {
    //     std::cerr << "invalid " << x << '\n';
    // }
    catch(...) {
        std::cerr << "invalid ALL INVALID\n";
    }
}

void calc(const std::smatch& match) {


    std::map<std::string, std::string> map;
    matchToMap(map, match);

    printMap(map);

    check(map);

}