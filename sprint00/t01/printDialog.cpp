#include "printDialog.h"

void printDialog(const std::string& name, const std::string& sentence) {

    if (empty(name) || empty(sentence))
        return;
    std::string str = name + " says: " + sentence;
    std::cout << str << std::endl;
}

// int main() {
//     std::string s1 = "ff";
//     std::string s2 = "Ooololo trololo!";
//     printDialog(s1, s2);
//     return 0;
// }
