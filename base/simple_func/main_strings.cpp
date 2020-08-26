#include <iostream>
#include <string>

void words() {
    std::string s;
    while (std::cin >> s)
        std::cout << s << '*';
    // std::cout << "\n\n";
}

void line() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << s;
    std::cout << "\n\n";
}

// int main() {
//     words();
//     return 0;
// }

int main() {
    line();
    return 0;
}