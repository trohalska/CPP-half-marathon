#include "FreezeSpell.h"

namespace Spells {

bool FreezeSpell::cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
    if (spellcaster.getMana() >= 30) {
        spellcaster.setMana(spellcaster.getMana() - 30);
        target.setHealth(target.getHealth() - 20);
        return true;
    }
    return false;
}

SpellType FreezeSpell::getType() const {
    return SpellType::Freeze;
}

}  // end namespace Spells
