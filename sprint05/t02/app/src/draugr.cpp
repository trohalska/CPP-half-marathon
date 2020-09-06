#include "draugr.h"

Draugr::Draugr()
    :Draugr(100., 50)
{};

Draugr::Draugr(int _frostResist)
    :Draugr(100., _frostResist)
{};

Draugr::Draugr(double _health, int _frostResist)
    :m_health(_health), m_frostResist(_frostResist)
{
    std::cout << "Draugr with "
              << _health << " health and "
              << _frostResist << "% frost resist was born!\n";
};

Draugr::Draugr(Draugr& other)
    :Draugr (other.m_health, other.m_frostResist)
{
    // m_name = other.m_name;
    std::cout << "Copy constructor was called\n";
}

Draugr::Draugr(Draugr&& other)
    :Draugr(std::move(other.m_health), std::move(other.m_frostResist))
{
    // m_name = other.m_name;
    std::cout << "Move constructor was called\n";
}

void Draugr::setName(const std::string&& name) {
    m_name = name;
}

void Draugr::shoutPhrase(int shoutNumber) const {
    std::map<int, std::string> hash = {
        {0, "Qiilaan Us Dilon!"},
        {1, "Bolog Aaz, Mal Lir!"},
        {2, "Kren Sosaal!"},
        {3, "Dir Volaan!"},
        {4, "Aar Vin Ok!"},
        {5, "Unslaad Krosis!"},
        {6, "Faaz! Paak! Dinok!"},
        {7, "Aav Dilon!"},
        {8, "Sovngarde Saraan!"}
    };
    std::cout << "Draugr " << m_name << " (" << m_health << " health, "
              << m_frostResist << "% frost resist) shouts:\n"
              << hash.at(shoutNumber) << std::endl;
}
