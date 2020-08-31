
#include "../../../mylib/mylib.h"

#include "../utils/algorithmUtils.h"

#include <vector>

int main() {
    std::cout << "Hello world!!!\n";
    std::cout << "In range " << IsInRange(20, 1, 10) << '\n';
    std::cout << "In range " << IsInRange(9, 1, 10) << '\n';

    std::string v = "yep";
    // std::string y = "yep";
    std::cout << "Modify " << Modify(v, "yep") << ' ' << v << '\n';

    std::vector<int> i = {1,5,8,9,1,4,5};

    // RemoveAll(i, 1);
    // RemoveAllIf(i, [](int x){return x > 2;});
    printVector(i);

    std::cout << *Find(i, 5) << ' ' << *FindIf(i, [](int x){return x > 8;});





    return 0;
}
