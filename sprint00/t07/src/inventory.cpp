#include "inventory.h"

static bool check(char item) {
    std::string s;

    std::getline(std::cin, s);
    if (s.length()) {
        std::cerr << "Invalid command.\n";
        return false;
    }
    if (item != 'w' && item != 'f' && item != 'a' && item != 'p') {
        std::cerr << "Invalid item.\n";
        return false;
    }
    return true;
}

void insert(std::vector<char>& inv) {
    char item;

    std::cin >> item;
    if (!check(item)) return;
    else if (inv.size() >= 12) std::cerr << "Inventory is full.\n";
    else {
        inv.push_back(item);
        std::cout << item << " was inserted.\n";
    }
}

void remove(std::vector<char>& inv) {
    char item;

    std::cin >> item;
    if (!check(item)) return;
    for (unsigned i = 0; i < inv.size(); ++i)
        if (inv[i] == item) {
            inv.erase(inv.begin() + i);
            break;
        }
    std::cout << item << " was removed.\n";
}

void show(std::vector<char>& inv) {
    std::cout << "Inventory {";
    for (unsigned i = 0; i < inv.size(); ++i)
        std::cout << " " << inv[i];
    if (inv.size() < 12)
        for (unsigned i = 0; i < 12 - inv.size(); ++i)
            std::cout << " -";
    std::cout << " }\n";
}

void help() {
    std::cout << "Available commands:\n";
    std::cout << "1. insert <itemType>\n";
    std::cout << "2. remove <itemType>\n";
    std::cout << "3. show inventory\n";
    std::cout << "4. help\n";
    std::cout << "5. exit\n";
}