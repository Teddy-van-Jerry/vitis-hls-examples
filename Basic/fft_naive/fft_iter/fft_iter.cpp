/**
 * @file fft_iter.cpp
 * @brief implementation iterative FFT modules
 * @author Wuqiong Zhao
 * @version 1.0 (2022-07-06)
 */

#include "fft_iter.h"
#include <iostream>

void bit_reverse(comp_t in[N], comp_t out[N]) {
    BIT_REVERSE: for (int i = 0; i != N; ++i) {
        out[bit_reverse_table[i]] = in[i];
    }
}

void fft_16(comp_t in[N], comp_t out[N]) {
    bit_reverse(in, out);
    STAGES: for (int s = 0; s != log2N; ++s) {
        int m = 2 << s;
        GROUPS: for (int k = 0; k < N; k += m) {
            BUTTERFLY: for (int j = 0; j != (m >> 1); ++j) {
                comp_t w = factors[j * N / m];
                comp_t t = w * out[k + j + (m >> 1)];
                comp_t u = out[k + j];
                out[k + j] = u + t;
                out[k + j + (m >> 1)] = u - t;
            }
        }
    }
}
