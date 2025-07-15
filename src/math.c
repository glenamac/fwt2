// src/math.c
#include <stdlib.h>
#include <string.h>
#include "fwt2/math.h"

double inner_prod(int N, double vec1[], double vec2[]) {
    double sum = 0.0;
    for (int i = 0; i < N; i++)
        sum += vec1[i] * vec2[i];
    return sum;
}

int getNumOctaves(int N) {
    int octaves = 0;
    while (N > 1) {
        N >>= 1;
        octaves++;
    }
    return octaves;
}

double *dn_sample(double **a, int N) {
    double *p    = *a;
    double *tmp  = malloc(N * sizeof *tmp);
    for (int i = 0; i < N; i++) {
        if ((i & 1) == 0)
            tmp[i/2]          = p[i];
        else
            tmp[(i-1)/2 + N/2] = p[i];
    }
    memcpy(p, tmp, N * sizeof *p);
    free(tmp);
    return p;
}

double *up_sample(double **a, int N) {
    double *p    = *a;
    double *tmp  = malloc(N * sizeof *tmp);
    for (int i = 0; i < N/2; i++) {
        tmp[2*i]     = p[i];
        tmp[2*i+1]   = p[i + N/2];
    }
    memcpy(p, tmp, N * sizeof *p);
    free(tmp);
    return p;
}

double *unirand(double *array, int N) {
    double *local = malloc(N * sizeof *local);
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++)
        local[i] = (double)rand() / RAND_MAX;
    return local;
}

double *poisson(double *lambda, int LENGTH) {
    double *local = malloc(LENGTH * sizeof *local);
    srand((unsigned)time(NULL));
    for (int i = 0; i < LENGTH; i++) {
        double L = exp(-lambda[i]);
        double p = 1.0;
        int k = 0;
        do {
            p *= (double)rand() / RAND_MAX;
            k++;
        } while (p >= L);
        local[i] = k - 1;
    }
    return local;
}

double *box_muller(double *sigma, int LENGTH) {
    double *local = malloc(LENGTH * sizeof *local);
    srand((unsigned)time(NULL));
    for (int i = 0; i < LENGTH; i++) {
        double u1 = (double)rand() / RAND_MAX;
        double u2 = (double)rand() / RAND_MAX;
        local[i] = sigma[i] * sqrt(-2.0 * log(u1)) * cos(2.0 * G_PI * u2);
    }
    return local;
}

