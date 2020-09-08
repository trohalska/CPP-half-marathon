#include <iostream>
#include "Creature.h"
#include "Spells/ISpell.h"

static std::string getSpellName(Spells::SpellType type) {
    if (type == Spells::SpellType::Healing)
        return "healing";
    else if (type == Spells::SpellType::Equilibrium)
        return "equilibrium";
    else if (type == Spells::SpellType::Flames)
        return "flames";
    else if (type == Spells::SpellType::Freeze)
        return "freeze";
    else if (type == Spells::SpellType::Fireball)
        return "fireball";
    return "Invalid";
}

namespace Creatures {

Creature::Creature(const std::string &name)
    : m_name(name), m_health(100), m_mana(100)
{
    std::cout << m_name << " was born!" << std::endl;
}

Creature::~Creature() {
    for (auto& it : m_spells)
        delete it;
}

void Creatures::Creature::learnSpell(Spells::ISpell *spell) {
    if (!m_spells.count(spell)) {
        m_spells.insert(spell);
        std::cout << m_name << " has learned the "
                  << getSpellName(spell->getType()) << " spell successfully!\n";
    } else {
        std::cout << m_name << " already knows the "
                  << getSpellName(spell->getType()) << " spell!\n";
    }
}

void Creature::castSpell(const Spells::SpellType type, Creature &creature) {

    Spells::ISpell *spell = nullptr;
    spell = *std::find_if(m_spells.begin(), m_spells.end(), [type](Spells::ISpell *item) {
        return item->getType() == type;
    });

    if (spell == nullptr)
        std::cout << m_name << " doesn't know the "
                  << getSpellName(type) << " spell." << std::endl;
    else if (spell->cast(*this, creature))
        std::cout << m_name << "> has cast the "
                  << getSpellName(type) << " spell on " << creature.getName()
                  << "!" << std::endl;
    else
        std::cout << m_name << " can't cast the "
                  << getSpellName(type) << "!" << std::endl;
}

std::string Creature::getName() const {
    return m_name;
    }
int Creature::getHealth() const {
    return m_health;
}
int Creature::getMana() const {
    return m_mana;
    }
void Creature::setHealth(int health) {
    m_health = health;
    if (m_health > 100)
        m_health = 100;
    else if (m_health < 0)
        m_health = 0;
}
void Creature::setMana(int mana) {
    m_mana = mana;
    if (m_mana > 100)
        m_mana = 100;
    else if (m_mana < 0)
        m_mana = 0;
}

};  // end namespace Creatures

std::ostream &operator<<(std::ostream &stream, const Creatures::Creature &creature) {
    stream << creature.getName() << " : " << creature.getHealth()
           << " HP, " << creature.getMana() << " MP.";
    return stream;
}
