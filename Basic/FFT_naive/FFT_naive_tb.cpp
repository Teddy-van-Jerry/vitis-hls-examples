/**
 * @file FFT_naive_tb.cpp
 * @brief FFT_naive module test bench
 * @author Wuqiong Zhao
 * @version 1.0 (2022-04-20)
 */

// standard C++ library
#include <vector>
#include <complex>

// HLS C++ library
#include <ap_int.h> // for integer types

const int a = 5;

int main() {
    std::vector<ap_int<a> > foo(4);
    for (int i = 0; i != 4; ++i) foo[i] = 2 * i - 1;
    for (int i = 0; i != 4; ++i) std::cout << foo[i] << ' ';
    std::cout << std::endl;
    return 0;
}
