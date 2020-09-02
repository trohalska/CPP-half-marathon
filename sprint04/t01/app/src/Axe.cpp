#include "Axe.h"

Axe::Axe(int axe_damage) : m_damage(axe_damage){}

int Axe::getDamage() const {
    return m_damage;
}
