#include <iostream>
#include "StormcloakSoldier.h"

StormcloakSoldier::StormcloakSoldier() {
    m_health = 100;
}
StormcloakSoldier::~StormcloakSoldier() {
    delete m_weapon;
}

void StormcloakSoldier::setWeapon(Axe *axe) {
    m_weapon = axe;
}
void StormcloakSoldier::consumeDamage(int amount) {
    m_health -= amount;
}
int StormcloakSoldier::getHealth() const {
    return m_health;
}
void StormcloakSoldier::attack(ImperialSoldier &enemy) {
    enemy.consumeDamage(m_weapon->getDamage());
    std::cout
    << "Stormcloak soldier attacks and deals "<< m_weapon->getDamage() << " damage\n"
    << "Imperial soldier consumes " << m_weapon->getDamage() << " of damage\n";
}
