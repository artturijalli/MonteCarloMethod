//
//  cell_search.cpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 15.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#include "cell_search.hpp"

int cell_search(std::vector<cell> cells, float x, float y, float z){
    for(int i = 0; i < cells.size(); ++i){
        if(cells[i].point_is_indside(x, y, z)) return i;
    }
    return -1;
}
