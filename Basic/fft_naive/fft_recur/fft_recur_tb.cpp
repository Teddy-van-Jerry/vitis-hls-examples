/**
 * @file fft_recur_tb.cpp
 * @brief fft_recur testbench
 * @details This recursive version cannot be synthesized.
 * @author Wuqiong Zhao
 * @version 1.0 (2022-07-05)
 */

#include "fft_recur.h"
#include <iostream>

void print(const comp_t* const arr) {
    for (int i = 0; i != N; ++i) {
        double real = arr[i].real();
        double imag = arr[i].imag();
        if (imag >= 0) {
            std::cout << real << "+" << imag;
        } else {
            std::cout << real << "-" << -imag;
        }
        std::cout << "i ";
    }
    std::cout << std::endl;
}

int main() {
    // check the compiler version
    // yields '6.2.0' on Vitis HLS 2021.2
    std::cout << "Compiler Version: " << __VERSION__ << std::endl;
#ifdef __VITIS_HLS__
    std::cout << "Running on Vitis HLS" << std::endl;
#else
    std::cout << "Running on Vivado HLS" << std::endl;
#endif

    comp_t x[N] = {
        comp(1.0, 2.0), comp(0.0, 0.0), comp(-0.5, 1.2), comp(-2.2, 0.1),
        comp(5.6, 2.2), comp(0.0, 4.1), comp(-0.5, 1.8), comp(1.4, 0.7),
        comp(1.4, -0.2), comp(5.6, 5.3), comp(-0.5, 1.2), comp(-2.0, -3.1),
        comp(1.3, 2.1), comp(0.3, -1.0), comp(-3.5, -0.2), comp(-2.5, 0.13)
    };
    comp_t y[N];
    fft_16(x, y);

print(y);

    return 0;
}
