#include <iostream>
#include <string>

template <typename T>
T absolute(T x) {
    return (x < 0) ? -x : x;
}

void use_template() {
    int8_t x8 = -1;
    int16_t x16 = -1;
    int32_t x32 = -1;
    int64_t x64 = -1;
    double xd = -1.1;
    float xf = -1.1;
    // std::string s = "hello";

    std::cout << absolute(x8) << std::endl;
    std::cout << absolute(x16) << std::endl;
    std::cout << absolute(x32) << std::endl;
    std::cout << absolute(x64) << std::endl;
    std::cout << absolute(xd) << std::endl;
    std::cout << absolute(xf) << std::endl;
    // std::cout << absolute(s) << std::endl;
    std::cout << absolute<double>(-18) << std::endl;
    // std::cout << absolute<int32_t>(-15.85) << std::endl;  // ошибка компилятора, невозможно
}

template<int num>
void self_counter() {
    static int32_t c = 0;
    c++;
    std::cout << "counter (number=" << num << ") " << c << std::endl;
}

int main() {
    // self_counter();   // ошибка компилятора, невозможно
    self_counter<1>();
    self_counter<1>();
    self_counter<1>();
    self_counter<2>();
    self_counter<2>();
    self_counter<1>();
    return 0;
}