#include "src/dwemerCalculator.h"

int main(int argc, char *argv[]) {

    while(1) {
        std::cout << ":>";

        std::string line;
        std::getline(std::cin, line);

        std::regex r1("^\\s*([?+|?-]{0,1}\\w+)\\s*([+|\\-|*|/]{1})\\s*([?+|?-]{0,1}\\w+)\\s*$");
        std::regex r2("^\\s*([?+|?-]{0,1}\\w+)\\s*([+|\\-|*|/]{1})\\s*([?+|?-]{0,1}\\w+)\\s*=\\s*([A-z]{1})\\s*");
        std::regex r3("^\\s*quit\\s*$");
        std::smatch match;

        // std::istringstream iss(line);
        // std::vector<std::string> v((std::istream_iterator<std::string>(iss)),
        //                          std::istream_iterator<std::string>());

        if (std::regex_search(line, match, r1)
            || std::regex_search(line, match, r2)) {
            calc(match);
        }
        else if (std::regex_match(line, match, r3))
            break;
        else
            std::cerr << "invalid input\n";
    }

    return 0;
}