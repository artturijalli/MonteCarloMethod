#ifndef buffons_needle_hpp
#define buffons_needle_hpp

#include <stdio.h>
#include <vector>
#include <math.h>
#include <numeric>

#include "statistical_analysis_methods.hpp"
#include "runtime_clock.hpp"
#include "global_params.hpp"

using namespace std;

extern vector<float> buffons_needle_probabilities_all;

float buffon_monte_carlo();
float buffons_needle_monte_carlo();
void stats_buffons_needle();

#endif /* buffons_needle_hpp */
