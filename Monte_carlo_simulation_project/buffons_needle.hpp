//
//  buffons_needle.hpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 7.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#ifndef buffons_needle_hpp
#define buffons_needle_hpp

#include <stdio.h>
#include <vector>
#include <math.h>
#include <numeric>

using namespace std;

extern vector<float> buffons_needle_probabilities_all;

float buffon_monte_carlo();
float buffons_needle_monte_carlo();
void stats_buffons_needle();

#endif /* buffons_needle_hpp */
