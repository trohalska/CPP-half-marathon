#include "Imperial.h"

namespace Creatures {

Imperial::Imperial(const std::string& name)
    : Creature(name)
{}

void Imperial::sayPhrase() const {
    std::cout << "I am " << getName() << ", Imperial soldier! Stop right here!" << std::endl;
}

};  // end namespace Creatures
