#pragma once
#include <iostream>
#include <string>
#include <map>
#include <regex>

class Draugr {
public:
    Draugr();
    Draugr(int _m_frostResist);
    Draugr(double _health, int _frostResist = 50);
    Draugr(Draugr& other);
    Draugr(Draugr&& other);

    void setName(const std::string&& name);
    void shoutPhrase(int shoutNumber) const;

private:
    double m_health;
    const int m_frostResist;
    std::string m_name;
};
