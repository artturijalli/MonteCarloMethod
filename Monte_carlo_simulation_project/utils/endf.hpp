//
//  endf.hpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 6.11.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#ifndef endf_hpp
#define endf_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

#include "helpers.hpp"

class endf
{
public:
    endf();
    ~endf();

    std::string symbol = "";
    int Z = 0, A = 0, NNU = 0;
    float AW = 0, T = 0;
    
    std::vector<float> energies, nubars, Qs;
    std::vector<int> MTs, NEs;
    std::vector<std::vector<float>> cross_section_energies, cross_sections;

    endf(std::string file_name);

    float cross_section_binary_search(float E, std::vector<int> MT_numbers);
};

#endif /* endf_hpp */
