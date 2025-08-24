#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <malloc.h>

// Note nBins must be a power of 2
// From https://en.wikipedia.org/wiki/Cooley-Tukey_FFT_algorithm
/*
 X0,...,N−1 ← ditfft2(x, N, s):             DFT of (x0, xs, x2s, ..., x(N-1)s):
    if N = 1 then
        X_0 ← x_0                                     trivial size-1 DFT base case
    else
        X_0,...,N/2−1 ← ditfft2(x, N/2, 2s)             DFT of (x0, x2s, x4s, ..., x(N-2)s)
        X_N/2,...,N−1 ← ditfft2(x+s, N/2, 2s)           DFT of (xs, xs+2s, xs+4s, ..., x(N-1)s)
        for k = 0 to (N/2)-1 do                      combine DFTs of two halves:
            p ← X_k
            q ← exp(−2πi/N k) X_(k+N/2)
            X_k ← p + q 
            X_(k+N/2) ← p − q
        end for
    end if
*/
complex* fftCooleyTukeyRecursive(double* x, size_t N, size_t s) {
    complex* X = (complex*) malloc(sizeof(complex) * N);
    
    // Basecase
    if(N == 1){
        X[0] = x[0];
        return X;
    }

    // Divide Case
    complex *first, *second, p, q;
    first = fftCooleyTukeyRecursive(x, N/2, 2*s);
    second = fftCooleyTukeyRecursive(&x[s], N/2, 2*s);


    // Combining the DFTs halves.
    for(int k=0; k<(N/2); ++k){
        p = first[k];
        q = cexp(-2*M_PI*I*k/N) * second[k];
        X[k] = p + q;
        X[k + N/2] = p - q;
    }
    free(first);
    free(second);
    return X;
}

void dft(double* signal, double* real, double* img, unsigned int nBins){
    /* Discrete Fourier Transform (DFT) formula:
        X[k] = sum(x_n * e ^((-j*2*pi*k*n)/N)
    */
    for(int k=0; k<nBins; k++){
        double realBin = 0;
        double imgBin = 0;
        for (int n = 0; n < nBins; n++) {
            double exponent = (2*M_PI*k*n)/nBins;
            realBin += signal[n]*cos(exponent);
            imgBin += signal[n]*sin(exponent);
        }
        real[k] = realBin/nBins;
        img[k] = imgBin/nBins;
    }
}



int main(int argc, char* argv[]){
    int fs = 8000;
    double signal[8] = {0, 0.707, 1, 0.707, 0, -0.707, -1, -0.707};
    double real[8] = {0};
    double img[8] = {0};
    unsigned int nBins = sizeof(signal)/sizeof(double);

    printf("Doing DFT for the following signal:\n");
    for(int i=0; i<nBins; i++){
        printf("%d: %.2f, ", i, signal[i]);
    }
    printf("\n");

    dft(signal, real, img, nBins);
    printf("Res in from naive DFT O(n^2) DFT:\n");
    for(int i=0; i<nBins/2; i++){
        printf("%dHz: %.2f + j%.2f, ", i*fs/nBins, real[i], img[i]);
    }
    printf("\n");

    complex* X = fftCooleyTukeyRecursive(signal, nBins, 1);
    printf("Res from Cooley-Tukey DFT O(nlogn):\n");
    for(int i=0; i<nBins/2; ++i){
        printf("%dHz: %.2f + j%.2f, ", i*fs/nBins, creal(X[i]), cimag(X[i]));
    }
    printf("\n");
    free(X);

    return 0;
}
