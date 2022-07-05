/**
 * @file fft_recur.cpp
 * @brief implementation recursive FFT modules
 * @details This recursive version cannot be synthesized.
 * @author Wuqiong Zhao
 * @version 1.0 (2022-07-05)
 */

#include "fft_recur.h"
#include <iostream>

void ditfft2(comp_t* in, int n, comp_t* out) {
    if (n == 1) {
        *out = *in;
    } else {
        // recursively call itself
        ditfft2(in, n >> 1, out);
        ditfft2(in + N / n, n >> 1, out + (n >> 1));
        // butterfly structure
        BUTTERFLY: for (int k = 0; k != n >> 1; ++k) {
            comp_t p = out[k];
            comp_t q = factors[k * N / n] * out[k + (n >> 1)];
            out[k] = p + q;
            out[k + (n >> 1)] = p - q;
        }
    }
}

void fft_16(comp_t in[N], comp_t out[N]) {
    ditfft2(in, N, out);
}
