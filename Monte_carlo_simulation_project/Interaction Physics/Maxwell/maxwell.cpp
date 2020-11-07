#include "maxwell.hpp"

float maxwell_sample(float T){
    float R = .0f;
    float r1 = .0f;
    float r2 = .0f;
    do
    {
        r1 = ((float)rand() / (RAND_MAX));
        r2 = ((float)rand() / (RAND_MAX));
        R = r1 * r1 + r2 * r2;
    } while (R > 1.0f);

    float r3 = ((float)rand() / (RAND_MAX));
    float r4 = ((float)rand() / (RAND_MAX));
    
    return -T * (r1 * r1 * log(r3) / R + log(r4));
}

float maxwell_fission_spectrum(float C0, float E, float T){
    return C0 * sqrt(E) * exp(-E / T);
}
