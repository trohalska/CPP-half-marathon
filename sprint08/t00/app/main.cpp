#include <regex>
#include <iostream>

#include "Player.h"
#include "Map.h"
#include "MoveManager.h"

static void check(int argc, char *argv[]) {
    std::regex r(R"lit(\d+)lit");
    std::cmatch match;

    if (argc != 3 || !std::regex_match(argv[1], match, r)
                  || !std::regex_match(argv[2], match, r)) {
        std::cerr << "usage: ./smartPointers [width] [height]" << std::endl;
        exit(EXIT_FAILURE);
    }
    size_t width = std::stoul(argv[1]);
    size_t heigh = std::stoul(argv[2]);

    if (width < 5 || width > 20 || heigh < 5 || heigh > 20) {
        std::cerr << "Invalid map size" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    check(argc, argv);

    std::shared_ptr<Player> player = std::make_shared<Player>();
    std::shared_ptr<Map> map = std::make_shared<Map>(std::stoul(argv[1]),
                                                     std::stoul(argv[2]), player);
    std::unique_ptr<MoveManager> manager = std::make_unique<MoveManager>(player, map);

    map->outputMap();
    while (1) {
        std::cout << ":> ";
        std::string s;
        std::getline(std::cin, s);

        manager->processInputAndMove(s);
        map->outputMap();
    }
    return 0;
}
