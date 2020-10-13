//
//  input_reader.cpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 7.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#include "input_reader.hpp"
#include <vector>

int M;
int N;
float D_LINES;
float L_NEEDLE;
float R_CIRCLE;

float A;
float B;
float C;
float D;
float E;
float F;
float G;
float H;
float I;
float J;

std::vector<std::vector<float>> input_structures;

void read_params(){
    std::fstream myfile("params.txt", std::ios_base::in);
    std::string a;
    myfile >> a >> M >> a >> N >> a >> D_LINES >> a >> L_NEEDLE >> a >> R_CIRCLE;
}

void read_csg_params(){
    std::fstream myfile("csg_params.txt", std::ios_base::in);
    std::string a;
    std::vector<float> structure_params;
    while(myfile >> a){
        if(!a.compare("A")){
            myfile >> A;
            structure_params.push_back(A);
        }
        if(!a.compare("B")){
            myfile >> B;
            structure_params.push_back(B);
        }
        if(!a.compare("C")){
            myfile >> C;
            structure_params.push_back(C);
        }
        if(!a.compare("D")){
            myfile >> D;
            structure_params.push_back(D);
        }
        if(!a.compare("E")){
            myfile >> E;
            structure_params.push_back(E);
        }
        if(!a.compare("F")){
            myfile >> F;
            structure_params.push_back(F);
        }
        if(!a.compare("G")){
            myfile >> G;
            structure_params.push_back(G);
        }
        if(!a.compare("H")){
            myfile >> H;
            structure_params.push_back(H);
        }
        if(!a.compare("I")){
            myfile >> I;
            structure_params.push_back(I);
        }
        if(!a.compare("J")){
            myfile >> J;
            structure_params.push_back(J);
            input_structures.push_back(structure_params);
            structure_params.clear();
        }
    }
}
