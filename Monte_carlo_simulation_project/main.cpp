//  main.cpp
//  PHYS-E0565_project
//  Created by Artturi Jalli on 28.9.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.

#include <iostream>
#include <algorithm>
#include <stdio.h>

#include "global_params.hpp"
#include "input_reader.hpp"
#include "buffons_needle.hpp"
#include "monte_carlo_pi_approximation_circle.hpp"
#include "monte_carlo_volume_sampling.hpp"
#include "endf.hpp"
#include "math_helpers.hpp"
#include "helpers.hpp"
#include "cross_section_data.hpp"



void round_1_assignment(){
    read_params();
    printf("M = %d \nN = %d \nIn Buffon's needle, the line width is %f \nNeedle length is %f \n\n", M, N, D_LINES, L_NEEDLE);
    stats_pi_approximation();
    stats_buffons_needle();
}

void round_2_assignment(){
    fuel_pin();
    hollow_cylinder();
}

void round_3_assignment(){
    get_asked_cross_section_datasets();
}
 
int main() {
    //round_1_assignment();
    //round_2_assignment();
    round_3_assignment();
}
