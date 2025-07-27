#include <stdio.h>
#include <math.h>



void fftCooleyTukeyRecursive(double* signal, double* real, double* img, unsigned int nBins){

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


    printf("Doing DFT O(n^2) for the following signal:\n");
    for(int i=0; i<nBins; i++){
        printf("%d: %.2f, ", i, signal[i]);
    }
    printf("\n");

    dft(signal, real, img, nBins);

    printf("Res in Freq Domain from O(n^2) DFT:\n");
    for(int i=0; i<nBins/2; i++){
        printf("%dHz: %.2f + j%.2f, ", i*fs/nBins, real[i], img[i]);
    }
    printf("\n");




    return 0;
}