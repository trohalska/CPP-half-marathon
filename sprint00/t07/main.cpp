#include "src/inventory.h"

int main() {
    std::string s;
    std::vector<std::string> cmd;
    std::vector<char> inv;

    while(1) {
        std::cout << "Enter command:> ";
        std::getline(std::cin, s);
        mysplit1(s, cmd, ' ');

        if (cmd.size() == 2) {
            if (cmd[0] == "insert") insert(inv, cmd[1]);
            else if (cmd[0] == "remove" ) remove(inv, cmd[1]);
            else std::cerr << "Invalid command.\n";
        }
        else if (cmd.size() == 1) {
            if (cmd[0] == "show") show(inv);
            else if (cmd[0] == "help") help();
            else if (cmd[0] == "exit") {
                std::cout << "Bye.\n";
                break;
            }
            else std::cerr << "Invalid command.\n";
        }
        else std::cerr << "Invalid command.\n";
        cmd.clear();
    }
    return 0;
}
