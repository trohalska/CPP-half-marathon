#include "printDialog.h"

void printDialog(const std::string& name, const std::string& sentence) {
    std::string str = name + " says: \"" + sentence + "\"\n";
    std::cout << str;
}

int main() {
    std::string s1 = "ff";
    std::string s2 = "Ooololo trololo!";
    printDialog(s1, s2);
    return 0;
}
