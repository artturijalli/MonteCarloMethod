//  main.cpp
//  PHYS-E0565_project
//  Created by Artturi Jalli on 28.9.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.

#include <iostream>

#include "global_params.hpp"
#include "input_reader.hpp"

#include "buffons_needle.hpp"
#include "monte_carlo_pi_approximation_circle.hpp"

void round_1_assignment(){
    read_params();
    printf("M = %d \nN = %d \nIn Buffon's needle, the line width is %f \nNeedle length is %f \n\n", M, N, D_LINES, L_NEEDLE);
    stats_pi_approximation();
    stats_buffons_needle();
}
 
int main() {
    round_1_assignment();
}
