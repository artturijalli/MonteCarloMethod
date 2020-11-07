#ifndef maxwell_hpp
#define maxwell_hpp

#include <stdio.h>
#include <math.h>


float maxwell_sample(float T);
float maxwell_fission_spectrum(float C0, float E, float T);

#endif /* maxwell_hpp */
