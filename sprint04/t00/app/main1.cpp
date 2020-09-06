
#include "../../../mylib/mylib.h"

#include "../utils/algorithmUtils.h"

#include <vector>

using namespace Utils;

int main() {
    std::vector<int> i = {1,5,8,9,1,1,1,4,5,2};

    // std::cout << "Hello world!!!\n";
    // std::cout << "In range " << IsInRange(20, 1, 10) << '\n';
    // std::cout << "In range " << IsInRange(9, 1, 10) << '\n';

    // std::string v = "yep";
    // std::string y = "yep";
    // std::cout << "Modify " << Modify(v, 32) << ' ' << v << '\n';

    // RemoveAll(i, 1);
    // RemoveAllIf(i, [](int x){return x > 2;});
    // printVector(i);

    // std::cout << *Find(i, 1) << ' ' << *FindIf(i, [](int x){return x > 8;}) << '\n';
    // printVector(i);

    // std::cout << Contains(i, 5) << ' ' << ContainsIf(i, [](int x){return x > 8;}) << '\n';
    // std::cout << Contains(i, 10) << ' ' << ContainsIf(i, [](int x){return x > 10;}) << '\n';
    // std::cout << CountIf(i, [](int x){return x > 4;}) << '\n';

    // std::cout << Min(50, 25, 35, 5) << '\n';
    // std::cout << Min(50) << '\n';
    // std::cout << Min(50, 3) << '\n';

    // std::cout << Max(50, 25, 35, 5) << '\n';
    // std::cout << Max(50) << '\n';
    // std::cout << Max(50, 3) << '\n';

    // std::cout << MaxElement(i) << ' ' << MinElement(i) << '\n';
    // std::cout << MaxElement(i, [](int a, int b){return a < 3 && b < 3;})
    //             << ' ' << '\n';

    // Sort(i);
    // Sort(i, [](int x, int y){ return x > y; });
    // printVector(i);

    // Unique(i);
    // printVector(i);
    // Unique(i, [](int x, int y){ return x == y; });
    // printVector(i);
    // ForEach(i, [](int x){ std::cout << x << " -*- "; });

    std::cout << IndexOf(i, 9) << " " << IndexOfIf(i, [](int x){ return x == 4; }) << '\n';

    return 0;
}
