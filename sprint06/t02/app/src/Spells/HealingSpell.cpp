#include "HealingSpell.h"

namespace Spells {

bool HealingSpell::cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
    if (spellcaster.getMana() >= 15) {
        spellcaster.setMana(spellcaster.getMana() - 15);
        target.setHealth(target.getHealth() + 10);
        return true;
    }
    return false;
}

SpellType HealingSpell::getType() const {
    return SpellType::Healing;
}

}  // end namespace Spells
