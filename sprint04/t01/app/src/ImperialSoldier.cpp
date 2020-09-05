#include <iostream>
#include "ImperialSoldier.h"

ImperialSoldier::ImperialSoldier() {
    m_health = 100;
    }
ImperialSoldier::~ImperialSoldier() {
    delete m_weapon;
}

void ImperialSoldier::setWeapon(Sword *sword) {
    m_weapon = sword;
}
void ImperialSoldier::consumeDamage(int amount) {
    m_health -= amount;
}
int ImperialSoldier::getHealth() const {
    return m_health;
}
void ImperialSoldier::attack(StormcloakSoldier &enemy) {
    enemy.consumeDamage(m_weapon->getDamage());
    std::cout
    << "Imperial soldier attacks and deals " << m_weapon->getDamage() << " damage\n"
    << "Stormcloak soldier consumes " << m_weapon->getDamage() << " of damage";
    if (enemy.getHealth() <= 0)
        std::cout << " and dies\n";
    else
        std::cout << "\n";
}