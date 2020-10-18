//
//  cell.cpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 14.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#include "cell.hpp"

cell::cell(){}

cell::cell(std::vector<quadratic_surface> quadratic_surfaces, std::vector<derived_surface> derived_surfaces){
    quadratic_surfaces = quadratic_surfaces;
    derived_surfaces = derived_surfaces;
}

bool cell::point_is_indside(float x, float y, float z){
    float eps = .0001f;
    bool is_inside = true;
    for(int i = 0; i < quadratic_surfaces.size(); ++i){
        if(quadratic_surfaces[i].surface_test(x, y, z) > eps){
            is_inside = false;
            break;
        }
    }
    
    if(is_inside){
        for(int i = 0; i < derived_surfaces.size(); ++i){
            if(derived_surfaces[i].surface_test(x, y, z) > 0){
                is_inside = false;
                break;
            }
        }
    }
    return is_inside;
}
