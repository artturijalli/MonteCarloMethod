//
//  derived_surface.hpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 14.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#ifndef derived_surface_hpp
#define derived_surface_hpp

#include <stdio.h>
#include <vector>

#include "quadratic_surface.hpp"

class derived_surface {
public:
    derived_surface();
    std::vector<quadratic_surface> quadratic_surfaces;
    
    bool is_complement;
    
    float surface_test(float x, float y, float z);
    float distance_function(float x, float y, float z, float u, float v, float w);
};

class truncated_cylinder : public derived_surface {
public:
    truncated_cylinder(cylinder cylinder, plane plane_1, plane plane_2, bool complemented);
};

class cuboid : public derived_surface {
public:
    cuboid(plane plane_1, plane plane_2, plane plane_3, plane plane_4, plane plane_5, plane plane_6, bool complemented);
};

class infinite_square_prism : public derived_surface {
public:
    infinite_square_prism(plane plane_1, plane plane_2, plane plane_3, plane plane_4, bool complemented);
};

#endif /* derived_surface_hpp */
