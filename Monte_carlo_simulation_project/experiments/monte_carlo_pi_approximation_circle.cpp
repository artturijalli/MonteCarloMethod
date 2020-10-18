//
//  monte_carlo_pi_approximation_circle.cpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 7.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#include "monte_carlo_pi_approximation_circle.hpp"

vector<float> pi_approximations_all;

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
    printf("Bonus excercise: WSTest result %f", WST_test(pi_approximations_all, STD(pi_approximations_all)));
    printf("\n\n");
}
