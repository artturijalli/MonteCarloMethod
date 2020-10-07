//  main.cpp
//  PHYS-E0565_project
//  Created by Artturi Jalli on 28.9.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <numeric>

#include "input_reader.hpp"
#include "statistical_analysis_methods.hpp"
#include "runtime_clock.hpp"

using namespace std;

vector<float> pi_approximations_all;
vector<float> buffons_needle_probabilities_all;

float buffon_monte_carlo(){
    int n_hits = 0;
    float p_needle_crossing_line;
    
    int j = 0;
    while(j < M){
        float x_rand = D_LINES * ((float) rand() / (RAND_MAX));
        float angle_rand = 180 * ((float) rand() / (RAND_MAX)) - 90;

        float x_min = -0.5 * cos(angle_rand * M_PI / 180.0f) * L_NEEDLE + x_rand;
        float x_max = 0.5 * cos(angle_rand * M_PI / 180.0f) * L_NEEDLE + x_rand;
        
        if(x_min <= 0 || D_LINES < x_max){
            n_hits++;
        }
        j++;
    }
    p_needle_crossing_line = (float)n_hits / M;
    return p_needle_crossing_line;
}

float circle_monte_carlo(){
    int n_in = 0;
    float pi_approx;
    
    int j = 0;
    while(j < M){
        float x_rand = ((float) rand() / (RAND_MAX));
        float y_rand = ((float) rand() / (RAND_MAX));
        float r = sqrt((x_rand * x_rand) + (y_rand * y_rand));
        
        if(r <= R_CIRCLE){
            n_in++;
        }
        j++;
    }
    pi_approx = 4 * (float)(n_in) / M;
    return pi_approx;
}

float buffons_needle_monte_carlo(){
    vector<float> probabilities;
    int i = 0;
    while(i < N){
        buffons_needle_probabilities_all.push_back(buffon_monte_carlo());
        probabilities.push_back(buffon_monte_carlo());
        i++;
    }
    float sum_of_probabilities = accumulate(probabilities.begin(), probabilities.end(), 0.0f);
    return sum_of_probabilities / (float)(N);
}

float approximate_pi_monte_carlo(){
    float sum_of_pi_approximations = 0;
    vector<float> pi_approximations;
    int i = 0;
    while(i < N){
        float pi_approximation = circle_monte_carlo();
        pi_approximations_all.push_back(pi_approximation);
        pi_approximations.push_back(pi_approximation);
        i++;
    }
    sum_of_pi_approximations = accumulate(pi_approximations.begin(), pi_approximations.end(), 0.0f);
    return sum_of_pi_approximations / (float)(N);
}

void stats_pi_approximation(){
    float runtime = run_with_timer(approximate_pi_monte_carlo);
    printf("MONTE CARLO - PI Approximation stats \n\n");
    printf("Runtime: %f seconds \n", runtime);
    printf("Mean: %f \n", mean(pi_approximations_all));
    printf("The Standard Deviation: %f \n", STD(pi_approximations_all));
    printf("Figure of Merit (FOM): %f \n", FOM(pi_approximations_all, runtime));
    printf("Bonus excercise: WSTest result %f", WSTest(pi_approximations_all, STD(pi_approximations_all)));
    printf("\n\n");
}

void stats_buffons_needle(){
    float runtime = run_with_timer(buffons_needle_monte_carlo);
    printf("Buffon's needle stats \n\n");
    printf("Runtime: %f seconds \n", runtime);
    printf("Mean: %f \n", mean(buffons_needle_probabilities_all));
    printf("The Standard Deviation: %f \n", STD(buffons_needle_probabilities_all));
    printf("Figure of Merit (FOM): %f \n", FOM(buffons_needle_probabilities_all, runtime));
    printf("Bonus excercise: WSTest result %f", WSTest(buffons_needle_probabilities_all, STD(buffons_needle_probabilities_all)));
    printf("\n\n");
}
 
int main()
{
    read_params();
    
    printf("M = %d \nN = %d \nIn Buffon's needle, the line width is %f \nNeedle length is %f \n\n", M, N, D_LINES, L_NEEDLE);
    
    stats_pi_approximation();
    stats_buffons_needle();
    
    getchar();
    return 0;
}
