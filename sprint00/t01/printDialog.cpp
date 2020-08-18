#include "printDialog.h"

void printDialog(const std::string& name, const std::string& sentence) {

    if (empty(name) || empty(sentence))
        return;
    std::string str = name + " says: " + sentence;
    std::cout << str << std::endl;
}
