/**
 * @file helloworld_tb.cpp
 * @brief helloworld module test bench
 * @author Wuqiong Zhao
 * @version 1.0 (2022-04-18)
 */

#include <iostream>
#include "helloworld.h"

int main() {
    int x = 15;
    int y = 0;
    helloworld(x, y); // use the top module
    std::cout << "Hello World!\nThe Result is y = " << y << std::endl;
    return 0;
}
