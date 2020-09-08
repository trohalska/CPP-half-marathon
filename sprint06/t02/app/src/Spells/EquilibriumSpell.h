#pragma once
#include "ISpell.h"

namespace Spells {

class EquilibriumSpell : public Spells::ISpell {
 public:
    bool cast(Creatures::Creature& spellcaster, Creatures::Creature& target);
    SpellType getType() const;
};

};  // end namespace Spells
