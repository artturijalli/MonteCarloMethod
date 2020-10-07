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
#include "buffons_needle.hpp"
#include "monte_carlo_pi_approximation_circle.hpp"
#include "global_params.hpp"

using namespace std;
 
int main()
{
    read_params();
    
    printf("M = %d \nN = %d \nIn Buffon's needle, the line width is %f \nNeedle length is %f \n\n", M, N, D_LINES, L_NEEDLE);
    
    stats_pi_approximation();
    stats_buffons_needle();
    
    getchar();
    return 0;
}
