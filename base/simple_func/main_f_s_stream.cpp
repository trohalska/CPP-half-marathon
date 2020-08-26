#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void read_array(int *A, int A_size, std::string f_name) {
    std::ifstream fin(f_name);
    for (int k = 0; k < A_size; ++k)
        fin >> A[k];
}

void sstr() {
    std::stringstream sout;
    sout << "x = " << 7 << "." << true << std::endl;
    std::string s;
    s = sout.str();
    std::cout << s;
}

int main() {
    // read_array
    sstr();
    return 0;
}