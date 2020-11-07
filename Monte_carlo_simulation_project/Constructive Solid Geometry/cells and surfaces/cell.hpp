//
//  cell.hpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 14.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#ifndef cell_hpp
#define cell_hpp

#include <stdio.h>
#include "quadratic_surface.hpp"
#include "derived_surface.hpp"

class cell{
public:
    cell();
    cell(std::vector<quadratic_surface> quadratic_surfaces, std::vector<derived_surface> derived_surfaces);
    std::vector<quadratic_surface> quadratic_surfaces;
    std::vector<derived_surface> derived_surfaces;
    
    bool point_is_indside(float x, float y, float z);
};

#endif /* cell_hpp */
