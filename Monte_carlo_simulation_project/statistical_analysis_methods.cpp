//
//  statistical_analysis_methods.cpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 7.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#include "statistical_analysis_methods.hpp"

float WSTest(vector<float> array, float std)
{
    float Q, range, min, max;
    min = *min_element(array.begin(), array.end());
    max = *max_element(array.begin(), array.end());
    range = max - min;

    Q = (float)range / std;

    return Q;
}

float mean(vector<float> values){
    auto n = values.size();
    float average = 0.0f;
    if (n != 0) {
        average = accumulate( values.begin(), values.end(), 0.0) / n;
    }
    return average;
}

float STD(vector<float> values){
    auto n = values.size();
    float values_squared_sum = 0;
    for (int i = 0; i < n; i++){
        values_squared_sum += values[i] * values[i];
    }
    float sum_values = accumulate(values.begin(), values.end(), 0.0);
    return sqrt((1.0f / ((float)n - 1.0f)) * ((values_squared_sum) - (1.0f / (float)n) * sum_values * sum_values));
}

float FOM(vector<float> values, float computing_time){
    return 1.0f / (STD(values) * STD(values) * computing_time);
}
