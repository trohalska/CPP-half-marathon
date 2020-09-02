#include "Sword.h"

Sword::Sword(int sword_damage) : m_damage(sword_damage) {}

int Sword::getDamage() const {
    return m_damage;
}
