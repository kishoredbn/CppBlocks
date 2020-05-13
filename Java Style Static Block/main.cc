#include <iostream>

#include "static_block.h"

void Test() {
    static int call_counter = 1;
    std::cout<<"function called : "<< call_counter++ <<" times \n";

    STATIC {
        std::cout<<"But this blocked will be called only once... \n";
    }

    STATIC {
        std::cout<<"And of course you can use it multiple times... \n";
    }

    STATIC std::cout<<"you can use it like this also, like an \"if\" statement\n";

    STATIC_N(3) {
        static int call_counter_block = 1;
        std::cout<<"Even better, you can specify how many times you want to execute the block\n";
        std::cout<<"********************** block called : "<< call_counter_block++ <<" times \n";
    }
}

int main() {

    Test();
    Test();
    Test();
    Test();
    Test();
    Test();
    Test();
    Test();
    Test();
    Test();

    return 0;
}