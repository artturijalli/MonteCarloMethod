//
//  helpers.cpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 6.11.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#include "helpers.hpp"

int get_index(std::vector<int> input_vector, int value)
{
    auto iterator = find(input_vector.begin(), input_vector.end(), value);
    return iterator != input_vector.end() ? iterator - input_vector.begin() : -1;
}
