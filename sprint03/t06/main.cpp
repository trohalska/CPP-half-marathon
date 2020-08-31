
// #include "../../mylib/mylib.h"

#include <vector>
#include "isPalindrome.h"


int main() {
    std::vector<int> m1 = { 1, 2, 3, 2, 1 };
    std::vector<double> m2 = { 0.1, 0.2, 0.3, 0.2, 0.1 };
    std::string m3 = "radar";

    std::cout << "1 = " << isPalindrome(m1.begin(), m1.end());
    std::cout << ", 2 = " << isPalindrome(m2.begin(), m2.end());
    std::cout << ", 3 = " << isPalindrome(m3.begin(), m3.end());

    return 0;
}
