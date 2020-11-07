//
//  monte_carlo_volume_sampling.cpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 18.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#include "monte_carlo_volume_sampling.hpp"

void fuel_pin(){
    printf("Demonstration of implemented routines\n");
    printf("Example 1: Fuel pin \n\n");
    int M = 1000000;
    printf("The number of randomly selected points inside a bounding box for this experiment is %d.\n\n", M);
    float x_max = 1.0f, x_min = -1.0f;
    float y_max = 1.0f, y_min = -1.0f;
    float z_max = 1.0f, z_min = 0.0f;
    float V_bounding = V_box(x_max - x_min, y_max - y_min, z_max - z_min);
    printf("Sampling between range: \n  - x from %.1f to %.1f\n  - y %.1f to %.1f\n  - z %.1f to %.1f \n\n", x_min, x_max, y_min, y_max, z_min, z_max);
    read_surfaces("input.txt");
    int j = 0;
    int fuel_hits = 0, cladding_hits = 0, coolant_hits = 0, outside_system_hits = 0;
    while (j < M) {
        j++;

        int index = cell_search(cells, random_between(x_min, x_max), random_between(y_min, y_max), random_between(z_min, z_max));
        if (index != -1) {
            if(index == 0){
                fuel_hits++;
            }else if(index == 1){
                cladding_hits++;
            }else if (index == 2){
                coolant_hits++;
            }else{
                outside_system_hits++;
            }
        }
    }
    printf("RESULTS: \n");
    printf("Fuel volume should be %f, and this experiment gave %f \n\n", V_cylinder(0.412f, 1.0f), V_cell(fuel_hits, M, V_bounding));
    printf("Cladding volume should be %f, and this experiment gave %f \n\n", V_cylinder(0.475, 1.0f) - V_cylinder(0.412f, 1.0f), V_cell(cladding_hits, M, V_bounding));
    printf("Coolant volume should be %f, and this experiment gave %f \n\n", V_box(1.33f, 1.33f, 1.0f) - V_cylinder(0.475, 1.0f), V_cell(coolant_hits, M, V_bounding));
    cells = {};
}

void hollow_cylinder(){
    int M = 1000000;
    printf("Example 2: Hollow cylinder, with two materials inside \n\n");
    printf("The number of randomly selected points inside a bounding box for this experiment is %d.\n\n", M);
    float x_max = 5.0f, x_min = -5.0f;
    float y_max = 5.0f, y_min = -5.0f;
    float z_max = 5.0f, z_min = -5.0f;
    float V_bounding = V_box(x_max - x_min, y_max - y_min, z_max - z_min);
    printf("Sampling between range: \n  - x from %.1f to %.1f\n  - y %.1f to %.1f\n  - z %.1f to %.1f \n\n", x_min, x_max, y_min, y_max, z_min, z_max);
    read_surfaces("input_2.txt");
    
    int j = 0;
    std::vector<cell> cells_ = cells;
    int top_material_hits = 0, bottom_material_hits = 0, cladding_material_hits = 0, outside_hits = 0;
    while (j < M) {
        j++;

        // Count the number of points falling inside each cell
        int index = cell_search(cells, random_between(x_min, x_max), random_between(y_min, y_max), random_between(z_min, z_max));
        if (index != -1) {
            if(index == 0){
                top_material_hits++;
            }else if(index == 1){
                bottom_material_hits++;
            }else if (index == 2){
                cladding_material_hits++;
            }else{
                outside_hits++;
            }
        }
    }
    printf("RESULTS: \n");
    printf("A cladding volume should be %f. The experiment gave %f \n", V_cylinder(2.05f, 7.1f) - V_cylinder(2.0f, 7.0f), V_cell(cladding_material_hits, M, V_bounding));
    printf("Material 1 and material 2 volume should be %f. The simulation gave us %f and %f respectively \n\n", V_cylinder(2.0f, 3.5f), V_cell(top_material_hits, M, V_bounding), V_cell(bottom_material_hits, M, V_bounding));
}
