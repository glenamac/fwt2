#ifndef FWT_NOISE_H
#define FWT_NOISE_H

#include <stddef.h>

/**
 * @brief Generate an array of Poisson-distributed samples.
 * @param lambda  Array of mean (λ) values, length N.
 * @param N       Number of samples / length of λ.
 * @return malloc’d array of length N containing Poisson samples, or NULL on error.
 *         Caller must free().
 */
double *fwt_poisson(const double *lambda, size_t N);


/**
 * @brief Generate an array of Gaussian (normal) -distributed samples
 *        via the Box–Muller transform.
 * @param sigma   Array of σ values (standard deviations), length N.
 * @param N       Number of samples / length of σ.
 * @return malloc’d array of length N containing Gaussian noise, or NULL on error.
 *         Caller must free().
 */
double *fwt_box_muller(const double *sigma, size_t N);


/**
 * @brief Generate an array of uniform [0,1) samples.
 * @param N  Number of samples.
 * @return malloc’d array of length N containing uniform randoms, or NULL on error.
 *         Caller must free().
 */
double *fwt_unirand(size_t N);

#endif // FWT_NOISE_H

