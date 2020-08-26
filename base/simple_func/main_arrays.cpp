#include <iostream>
#include <string>

struct student {
    int8_t age;
    int16_t group;
    std::string name;
};

void init(double** A, int8_t h, int8_t w) {
    for (int k = 0; k < h; ++k)
        for (int j = 0; j < w; ++j)
            A[k][j] = 1 + k * w +j;
}
void printer(double** A, int8_t h, int8_t w) {
    for (int k = 0; k < h; ++k) {
        for (int j = 0; j < w; ++j)
            std::cout << A[k][j] << '\t';
        std::cout << std::endl;
    }
}

// ---------------------------- Структуры и указатели

void struct_point() {
    student vasya = {17, 649, "Vasya ivanov"};
    std::cout << vasya.name;

    student *p = nullptr;
    p = &vasya;
    std::cout << p->name;
}

// ---------------------------- Динамическая память, массивы

void arr() {
    int8_t len = 10;
    student *p = new student[len];
    for (int k = 0; k < len; ++k) {
        p[k].name = "vasya";
        p[k].age = 17;
        p[k].group = 600 + k;
    }
}

void double_arr() {
    int8_t h = 3, w = 4;

    double** A = nullptr;
    A = new double* [h];
    for (int k = 0; k < h; ++k)
        A[k] = new double[w];

    init(A, h, w);
    printer(A, h, w);

    for (int k = 0; k < h; ++k)
        delete[] A[k];
    delete[] A;

    // Запрос одного большого куска памяти (один new)

    double** B = nullptr;
    B = new double* [h];
    B[0] = new double[w*h];
    for (int k = 0; k < h; ++k)
        B[k] = B[0] + k*w;

    init(B, h, w);
    printer(B, h, w);

    delete[] B[0];
    delete[] B;
}

int main() {
    double_arr();
    return 0;
}