//
//  input_reader.cpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 7.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#include "input_reader.hpp"

int M;
int N;
float D_LINES;
float L_NEEDLE;
float R_CIRCLE;

void read_params(){
    std::fstream myfile("params.txt", std::ios_base::in);
    std::string a;
    myfile >> a >> M >> a >> N >> a >> D_LINES >> a >> L_NEEDLE >> a >> R_CIRCLE;
}
