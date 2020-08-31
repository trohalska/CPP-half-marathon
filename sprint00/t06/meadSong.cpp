#include "meadSong.h"

static void printFirst(int32_t i) {

    i == 0 ? std::cout << "No more bottles" :
    i == 1 ? std::cout << i << " bottle" : std::cout << i << " bottles";
    std::cout << " of mead on the wall, ";
    i == 0 ? std::cout << "no more bottles" :
    i == 1 ? std::cout << i << " bottle" : std::cout << i << " bottles";
    std::cout << " of mead." << std::endl;
}

static void printSecond(int32_t i, int32_t count) {

    i == -1 ? std::cout << "Go to the store and buy some more, " :
    i == 0 ? std::cout << "Take it " : std::cout << "Take one ";
    i >= 0 ? std::cout << "down and pass it around, " : std::cout << "";

    i == 0 ? std::cout << "no more bottles" :
    i == -1 ? std::cout << count << " bottles" :
    i == 1 ? std::cout << i << " bottle" : std::cout << i << " bottles";

    std::cout << " of mead on the wall." << "\n\n";
}

void createMeadSong(int32_t count) {
    int32_t i = count;

    while (i >= 0) {
        printFirst(i);
        printSecond(--i, count);
    }
}