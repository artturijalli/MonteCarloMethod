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
    linspaced.push_back(end);
    return linspaced;
}

float V_cell(float N_inside, float N_total, float V_bounding_box){
    return V_bounding_box * (N_inside / N_total);
}

float V_sphere(float r){
    return (4.0f/3.0f) * M_PI * r * r * r;
}

float V_cylinder(float r, float h){
    return M_PI * r * r * h;
}

float V_box(float a, float b, float c){
    return a * b * c;
}

float random_between(float min, float max){
    return ((float)rand() / (RAND_MAX)) * (max - min) + min;
}
