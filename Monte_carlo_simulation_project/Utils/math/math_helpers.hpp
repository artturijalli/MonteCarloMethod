//
//  math_helpers.hpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 6.11.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#ifndef math_helpers_hpp
#define math_helpers_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

std::vector<float> linspace(float start_in, float end_in, int num_in);

float V_cell(float N_inside, float N_total, float V_bounding_box);
float V_sphere(float r);
float V_cylinder(float r, float h);
float V_box(float a, float b, float c);

float random_between(float min, float max);

#endif /* math_helpers_hpp */
