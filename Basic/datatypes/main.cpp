/**
 * @file main.cpp
 * @brief data types and basic operations test
 * @author Wuqiong Zhao
 * @version 1.0 (2022-05-09)
 */

#include <iostream>
#include <ap_int.h>
#include <ap_fixed.h>

int main() {
    std::cout << "Compiler Version: " __VERSION__ << std::endl;

    /***** Integer *****/
    ap_int<4> i1 = 2;
    std::cout << "i1 = " << i1 << std::endl;
    i1 = 0b0101; // 5
    std::cout << "i1 = " << i1 << std::endl;
    i1 *= 2; // -6 (overflow)
    std::cout << "i1 = " << i1 << std::endl;
    i1 >>= 1; // -3 (right shift 1)
    std::cout << "i1 = " << i1 << std::endl;
    // convert to a binary string
    std::cout << "i1 = " << i1.to_string(2) << std::endl;
    // access the element at location 1
    std::cout << "i1[1] = " << i1[1] << std::endl;

    /***** Float *****/
    ap_fixed<6, 4> f1 = 3.1415926; // 3
    // 6 bits data, 4 bits before left of the binary point
    // therefore 1 sign, 3 int, 2
    std::cout << "f1 = " << f1 << std::endl;
    ap_fixed<6, 4> f2 = 5.99; // 5.75
    // the default behavior, truncation to minus infinity
    std::cout << "f2 = " << f2 << std::endl;
    ap_fixed<6, 4, AP_RND> f3 = 5.99;
    // round to plus infinity
    std::cout << "f3 = " << f3 << std::endl;
    f3 += ap_fixed<6, 4>(3.3); // -6.75 (overflow)
    std::cout << "f3 = " << f3 << std::endl;
    ap_ufixed<6, 4> f4 = 12.34; // 12.25
    std::cout << "f4 = " << f4 << std::endl;
    f4 += 4; // 0.25 (overflow)
    std::cout << "f4 = " << f4 << std::endl;

    return 0;
}
