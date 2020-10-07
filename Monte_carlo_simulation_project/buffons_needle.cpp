//
//  buffons_needle.cpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 7.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#include "buffons_needle.hpp"
#include "statistical_analysis_methods.hpp"
#include "runtime_clock.hpp"
#include "global_params.hpp"

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
