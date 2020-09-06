#include "draugr.h"

Draugr::Draugr() : m_health(100), m_frostResist(50) {};

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
    std::cout << "Draugr ("
              << m_health << " health, "
              << m_frostResist << "% frost resist) shouts:\n"
              << hash.at(shoutNumber) << std::endl;
}
