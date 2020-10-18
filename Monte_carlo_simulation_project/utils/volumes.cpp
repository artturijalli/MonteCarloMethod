//
//  volumes.cpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 18.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#include "volumes.hpp"

float V_cell(float N_inside, float N_total, float V_bounding_box){
    return V_bounding_box * (N_inside / N_total);
}

float V_sphere(float r){
    return (4.0f/3.0f) * M_PI * r * r * r;
}

float V_cylinder(float r, float h){
    return M_PI * r * r * h;
}

float V_box(float a, float b, float c){
    return a * b * c;
}
