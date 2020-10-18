//
//  random.cpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 18.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#include "random.hpp"

float random_between(float min, float max){
    return ((float)rand() / (RAND_MAX)) * (max - min) + min;
}
