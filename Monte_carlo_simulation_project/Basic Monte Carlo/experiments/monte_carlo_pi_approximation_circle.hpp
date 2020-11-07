#ifndef monte_carlo_pi_approximation_circle_hpp
#define monte_carlo_pi_approximation_circle_hpp

#include <stdio.h>
#include <vector>
#include <math.h>
#include <numeric>

#include "statistical_analysis_methods.hpp"
#include "runtime_clock.hpp"
#include "global_params.hpp"

using namespace std;

extern vector<float> pi_approximations_all;

float circle_monte_carlo();
float approximate_pi_monte_carlo();
void stats_pi_approximation();
#endif /* monte_carlo_pi_approximation_circle_hpp */
