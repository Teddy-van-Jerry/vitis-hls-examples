/**
 * @file fft_recur.h
 * @brief recursive FFT modules
 * @details This recursive version cannot be synthesized.
 * @author Wuqiong Zhao
 * @version 1.0 (2022-07-05)
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

static inline comp_t comp(real_t r, real_t i) {
    return comp_t(r, i);
}

static inline std::array<comp_t, N / 2> fft_factors() {
    std::array<comp_t, N / 2> w;
    for (int k = 0; k != N / 2; ++k) {
        std::complex<double> tmp = {0.0, -2.0 * pi * k / N};
        std::complex<double> w_k = std::exp(tmp);
        w[k].real(w_k.real());
        w[k].imag(w_k.imag());
    }
    return w;
}

static const std::array<comp_t, N / 2> factors = fft_factors();

/**
 * @brief radix-2 FFT with arbitrary length
 * 
 * @details This is based on the Cooley-Tukey algorithm.
 * @param in input data array
 * @param n length of the array (should be a power of 2)
 * @param out output transformed array
 */
void ditfft2(comp_t* in, int n, comp_t* out);

/**
 * @brief TOP function: N points FFT
 *
 * @param in input data array (N points)
 * @param out output data array
 */
void fft_16(comp_t in[N], comp_t out[N]);

#endif
