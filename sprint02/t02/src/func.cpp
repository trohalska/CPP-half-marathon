#include "header.h"

void handle_cin(std::map<std::string, std::string>& lib) {
    while(1) {
        std::cout << "enter command:> ";
        std::string cinline;
        std::getline(std::cin, cinline);
        std::istringstream iss(cinline);
        std::vector<std::string> cmd((std::istream_iterator<std::string>(iss)),
                                 std::istream_iterator<std::string>());
        if (cmd.size() == 2) {
            if (cmd[0] == "add")
                add(lib, cmd[1]);
            else if (cmd[0] == "delete")
                remove(lib, cmd[1]);
            else if (cmd[0] == "read")
                read(lib, cmd[1]);
            else
                std::cerr << "invalid command\n";
        } else if (cmd.size() == 1) {
            if (cmd[0] == "list")
                list(lib);
            else if (cmd[0] == "help")
                help();
            else if (cmd[0] == "quit") {
                std::cout << "bye\n";
                break;
            }
            else
                std::cerr << "invalid command\n";
        } else if (cmd.size() == 0) {
            continue;
        } else
            std::cerr << "invalid command\n";
    }
}

void add(std::map<std::string, std::string>& lib, const std::string& b) {
    fileToMap(lib, b);
}

void remove(std::map<std::string, std::string>& lib, const std::string& b) {
    auto x = lib.find(b);
    if (x == lib.end())
        std::cerr << "invalid book\n";
    else {
        lib.erase(x);
        std::cout << b << " deleted\n";
    }
}

void read(const std::map<std::string, std::string>& lib, const std::string& b) {
    auto x = lib.find(b);
    if (x == lib.end())
        std::cerr << "invalid book\n";
    else
        std::cout << x->second;
}

void list(const std::map<std::string, std::string>& lib) {
    for (auto [book, item] : lib)
        std::cout << book << std::endl;
}

void help() {
    std::cout << "\nAvailable commands:\n";
    std::cout << "1. add <bookName>\n";
    std::cout << "2. delete <bookName>\n";
    std::cout << "3. read <bookName>\n";
    std::cout << "4. list\n";
    std::cout << "5. help\n";
    std::cout << "6. quit\n\n";
}