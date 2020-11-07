//
//  helpers.hpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 6.11.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#ifndef helpers_hpp
#define helpers_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

int get_index(std::vector<int> v, int K);
void print_vector(std::vector<float> vec);
std::vector<int> range_vector(int start, int end, int interval);


#endif /* helpers_hpp */
