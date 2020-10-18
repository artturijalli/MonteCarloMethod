//
//  volumes.hpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 18.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#ifndef volumes_hpp
#define volumes_hpp

#include <stdio.h>
#include <math.h>

float V_cell(float N_inside, float N_total, float V_bounding_box);
float V_sphere(float r);
float V_cylinder(float r, float h);
float V_box(float a, float b, float c);

#endif /* volumes_hpp */
