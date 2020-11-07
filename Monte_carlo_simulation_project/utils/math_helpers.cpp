//
//  math_helpers.cpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 6.11.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#include "math_helpers.hpp"
#include <iostream>
#include <vector>

std::vector<float> linspace(float start_in, float end_in, int num_in)
{

    std::vector<float> linspaced;

    float start = static_cast<float>(start_in);
    float end = static_cast<float>(end_in);
    float num = static_cast<float>(num_in);

    if (num == 0) { return linspaced; }
    if (num == 1){
      linspaced.push_back(start);
      return linspaced;
    }

    float delta = (end - start) / (num - 1);

    for(int i=0; i < num-1; ++i){
      linspaced.push_back(start + delta * i);
    }
    linspaced.push_back(end); // I want to ensure that start and end
                            // are exactly the same as the input
    return linspaced;
}
