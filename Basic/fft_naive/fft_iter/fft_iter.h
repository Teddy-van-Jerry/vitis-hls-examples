/**
 * @file fft_iter.h
 * @brief iterative FFT modules
 * @author Wuqiong Zhao
 * @version 1.0 (2022-07-06)
 */

#ifndef _FFT_RECUR_H_
#define _FFT_RECUR_H_

#include <ap_fixed.h> // ap_fixed
#include <complex> // std::complex
#include <array> // std::array

const int W_INT = 4 + 1; // width of integer part, including the sign
const int W_DEC = 6;     // width of decimal part
const int log2N = 4;
const int N = 1 << log2N; // bits (a power of 2)

typedef ap_fixed<W_INT + W_DEC, W_DEC> real_t; // real number data type
typedef std::complex<real_t> comp_t; // complex number data type

const double pi = 3.1415926535897932384625;

static const int bit_reverse_table[N] = {
    0x0, 0x8, 0x4, 0xc, 0x2, 0xa, 0x6, 0xe,
    0x1, 0x9, 0x5, 0xd, 0x3, 0xb, 0x7, 0xf
};

static inline comp_t comp(real_t r, real_t i) {
    return comp_t(r, i);
}

static inline std::array<comp_t, N / 2> fft_factors() {
    std::array<comp_t, N / 2> w;
    std::complex<double> w0 = { std::cos(-2.0 * pi / N), std::sin(-2.0 * pi / N) };
    std::complex<double> _w = { 1.0, 0 };
    for (int k = 0; k != N / 2; ++k) {
        std::complex<double> w_k = _w;
        w[k].real(w_k.real());
        w[k].imag(w_k.imag());
        _w *= w0;
    }
    return w;
}

static const std::array<comp_t, N / 2> factors = fft_factors();

/**
 * @brief bit-reversal permutation
 * 
 * @details Here we use table looking up methods.
 * @param in input data
 * @param out reversed data
 */
static void bit_reverse(comp_t in[N], comp_t out[N]);

/**
 * @brief TOP function: N points FFT
 *
 * @param in input data array (N points)
 * @param out output data array
 */
void fft_16(comp_t in[N], comp_t out[N]);

#endif
