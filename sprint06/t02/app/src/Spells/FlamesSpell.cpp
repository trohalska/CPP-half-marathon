#include "FlamesSpell.h"

namespace Spells {

bool FlamesSpell::cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
    if (spellcaster.getMana() >= 14) {
        spellcaster.setMana(spellcaster.getMana() - 14);
        target.setHealth(target.getHealth() - 8);
        return true;
    }
    return false;
}

SpellType FlamesSpell::getType() const {
    return SpellType::Flames;
}

}  // end namespace Spells
