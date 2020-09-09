#include "Redguard.h"

namespace Creatures {

Redguard::Redguard(const std::string& name)
    : Creature(name)
{}

void Redguard::sayPhrase() const {
    std::cout << "I am " << getName() << " from Redguards, wanna trade?" << std::endl;
}

};  // end namespace Creatures
