#include <vector>
#include "outputContainer.h"

int main() {
    std::vector<int> myvector;
    for (int i=1; i<10; ++i) myvector.push_back(i*10);

    outputContainer(myvector);

    return 0;
}
