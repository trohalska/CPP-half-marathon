#include "referenceOrPointer.h"

void multiplyByPointer(int* ptr, int mult) {
    std::cout << mult * *ptr << std::endl;
}

void multiplyByReference(int& ref, int mult) {
    std::cout <<  mult * ref << std::endl;
}