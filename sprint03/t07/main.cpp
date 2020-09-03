
#include "../../mylib/mylib.h"

#include <vector>
#include "sortValues.h"


int main() {
    std::vector<int> m1 = { 9, 2, 3, 2, 1 };
    std::vector<double> m2 = { 0.1, 0.2, 0.3, 0.2, 0.1 };
    std::string m3 = "radar";

    sortValues(m1.begin(), m1.end());
    outputAny(m1);

    sortValues(m2.begin(), m2.end());
    outputAny(m2);

    sortValues(m3.begin(), m3.end());
    std::cout << m3;

    return 0;
}
