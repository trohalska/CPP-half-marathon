#include <iostream>

#include "Creatures/Imperial.h"
#include "Creatures/Redguard.h"
#include "Spells/EquilibriumSpell.h"
#include "Spells/FireballSpell.h"
#include "Spells/FlamesSpell.h"
#include "Spells/FreezeSpell.h"
#include "Spells/HealingSpell.h"

// int main() {
//     using namespace Creatures;
//     using namespace Spells;

//     std::string redgardName = "JoJo";
//     Redguard red(redgardName);
//     red.sayPhrase();
//     std::string imperialName = "Dio";
//     Imperial imp(imperialName);
//     imp.sayPhrase();

//     std::cout << red << std::endl;
//     std::cout << imp << std::endl;

//     HealingSpell* healing = new HealingSpell;
//     EquilibriumSpell* equilibrium = new EquilibriumSpell;
//     FlamesSpell* flames = new FlamesSpell;
//     FreezeSpell* freeze = new FreezeSpell;
//     FireballSpell* fireball = new FireballSpell;

//     red.learnSpell(healing);
//     red.learnSpell(fireball);

//     imp.learnSpell(equilibrium);
//     imp.learnSpell(equilibrium);

//     red.castSpell(SpellType::Fireball, imp);
//     imp.castSpell(SpellType::Equilibrium, red);

//     std::cout << red << std::endl;
//     std::cout << imp << std::endl;

//     imp.castSpell(SpellType::Flames, red);

//     imp.learnSpell(flames);
//     imp.learnSpell(freeze);

//     red.castSpell(SpellType::Healing, red);
//     imp.castSpell(SpellType::Freeze, red);

//     std::cout << red << std::endl;
//     std::cout << imp << std::endl;

//     red.castSpell(SpellType::Fireball, imp);
//     red.castSpell(SpellType::Fireball, imp);
//     red.castSpell(SpellType::Fireball, imp);

//     std::cout << red << std::endl;
//     std::cout << imp << std::endl;

//     return 0;
// }

int main() {
    using namespace Creatures;
    using namespace Spells;

    std::string redguardName = "JoJo";
    Creatures::Redguard red(redguardName);
    red.sayPhrase();
    std::string imperialName = "Dio";
    Creatures::Imperial imp(imperialName);
    imp.sayPhrase();
    std::cout << " - "<< red<< std::endl;
    std::cout<< " - "<< imp<< std::endl;

    Spells::HealingSpell* healing= new Spells::HealingSpell;
    Spells::EquilibriumSpell* equilibrium= new Spells::EquilibriumSpell;
    Spells::FlamesSpell* flames= new Spells::FlamesSpell;
    Spells::FreezeSpell* freeze= new Spells::FreezeSpell;
    Spells::FireballSpell* fireball= new Spells::FireballSpell;

    red.learnSpell(healing);
    red.learnSpell(fireball);

    imp.learnSpell(equilibrium);
    imp.learnSpell(equilibrium);

    red.castSpell(Spells::SpellType::Fireball, imp);

    std::cout<< " - "<< red<< std::endl;
    std::cout<< " - "<< imp<< std::endl;

    imp.castSpell(Spells::SpellType::Equilibrium, red);

    std::cout<< " - "<< red<< std::endl;
    std::cout<< " - "<< imp<< std::endl;

    imp.castSpell(Spells::SpellType::Flames, red);

    imp.learnSpell(flames);
    imp.learnSpell(freeze);

    red.castSpell(Spells::SpellType::Healing, red);

    std::cout<< " - "<< red<< std::endl;
    std::cout<< " - "<< imp<< std::endl;

    imp.castSpell(Spells::SpellType::Freeze, red);

    std::cout<< " - "<< red<< std::endl;
    std::cout<< " - "<< imp<< std::endl;

    red.castSpell(Spells::SpellType::Fireball, imp);

    std::cout<< " - "<< red<< std::endl;
    std::cout<< " - "<< imp<< std::endl;

    red.castSpell(Spells::SpellType::Fireball, imp);

    std::cout<< " - "<< red<< std::endl;
    std::cout<< " - "<< imp<< std::endl;

    red.castSpell(Spells::SpellType::Fireball, imp);
    std::cout<< " - "<< red<< std::endl;
    std::cout<< " - "<< imp<< std::endl;

    return 0;


}