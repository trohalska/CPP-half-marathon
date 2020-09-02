#include "dragonborn.h"

void Dragonborn::executeAction(const Actions action) {

    std::map<Actions, void (Dragonborn::*)() const> hashtable;
    hashtable[Actions::Shout] = &Dragonborn::shoutThuum;
    hashtable[Actions::Magic] = &Dragonborn::attackWithMagic;
    hashtable[Actions::Weapon] = &Dragonborn::attackWithWeapon;

    std::invoke(hashtable[action], this);
}
void Dragonborn::shoutThuum() const {
    std::cout << "Yol Toor Shul\n";
}
void Dragonborn::attackWithMagic() const {
    std::cout << "*attacks with magic spell*\n";
}
void Dragonborn::attackWithWeapon() const {
    std::cout << "*attacks with weapon*\n";
}
