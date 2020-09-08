#include "EquilibriumSpell.h"

namespace Spells {

bool EquilibriumSpell::cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
    if (spellcaster.getHealth() > 25) {
        spellcaster.setHealth(spellcaster.getHealth() - 25);
        target.setMana(target.getMana() + 25);
        return true;
    }
    return false;
}

SpellType EquilibriumSpell::getType() const {
    return SpellType::Equilibrium;
}

}  // end namespace Spells
