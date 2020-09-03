#include "sumFileData.h"

int main(int args, char *argv[]) {

    if(args < 2)
        return 1;
    std::cout << "sum = " << sumFileData<int>(argv[1]) << std::endl;
    std::cout << "sum = " << sumFileData<double>(argv[2]) << std::endl;

    return 0;
}
