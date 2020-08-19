// #include <vector>
#include "src/inventory.h"

int main() {
    std::string cmd;
    std::vector<char> inv;

    while(1) {
        std::cout << "Enter command:> ";
        std::cin >> cmd;
        if (cmd == "insert") insert(inv);
        else if (cmd == "remove" ) remove(inv);
        else if (cmd == "show") show(inv);
        else if (cmd == "help") help();
        else if (cmd == "exit") {
            std::cout << "Bye.\n";
            break;
        }
        else std::cerr << "Invalid command." << std::endl;
    }
    return 0;
}
