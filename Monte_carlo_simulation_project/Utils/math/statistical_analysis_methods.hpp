//
//  statistical_analysis_methods.hpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 7.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#ifndef statistical_analysis_methods_hpp
#define statistical_analysis_methods_hpp

#include <stdio.h>
#include <vector>
#include <numeric>

using namespace std;

float WST_test(vector<float> array, float std);
float mean(vector<float> values);
float STD(vector<float> values);
float FOM(vector<float> values, float computing_time);

#endif /* statistical_analysis_methods_hpp */
