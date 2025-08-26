#include "differentiate.h"
#include <math.h>
#include <stdio.h>   // for _popen, fprintf
#define SIGNAL_LEN 1000
#define SAMPLE_FREQ 100

int main(int argc, char *argv[])
{
    double signal[SIGNAL_LEN] = {0};
    for(int t = 0; t < SIGNAL_LEN; ++t){
        signal[t] = sin(2.0 * M_PI * 1.0 / SAMPLE_FREQ * t);
    }
    double *derivative = differentiate(signal, SIGNAL_LEN);

    // Normalise Derivative
    double peak = 0;
    for(int i=0; i<SIGNAL_LEN-1; ++i){
        if(derivative[i] > peak)
            peak = derivative[i];
    }
    for(int i=0; peak != 0 && i<SIGNAL_LEN-1; ++i){
        derivative[i] = derivative[i]/peak;
    }

    FILE *gnuplot = _popen("gnuplot -persistent", "w");
    if (gnuplot == NULL) {
        fprintf(stderr, "Could not open gnuplot\n");
        return 1;
    }

    fprintf(gnuplot, "set title 'Signal and Derivative'\n");
    fprintf(gnuplot, "set xlabel 't (samples)'\n");
    fprintf(gnuplot, "set ylabel 'Value'\n");
    fprintf(gnuplot, "plot '-' with lines title 'Signal', '-' with lines title 'Derivative'\n");

    for (int t = 0; t < SIGNAL_LEN; ++t)
        fprintf(gnuplot, "%d %f\n", t, signal[t]);
    fprintf(gnuplot, "e\n");

    for (int t = 0; t < SIGNAL_LEN; ++t)
        fprintf(gnuplot, "%d %f\n", t, derivative[t]);
    fprintf(gnuplot, "e\n");

    fflush(gnuplot);
    _pclose(gnuplot);
    free(derivative);

    return 0;
}

