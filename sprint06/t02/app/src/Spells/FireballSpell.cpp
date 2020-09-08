#include "FireballSpell.h"

namespace Spells {

bool FireballSpell::cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
    if (spellcaster.getMana() >= 50) {
        spellcaster.setMana(spellcaster.getMana() - 50);
        target.setHealth(target.getHealth() - 40);
        return true;
    }
    return false;
}

SpellType FireballSpell::getType() const {
    return SpellType::Fireball;
}

}  // end namespace Spells
