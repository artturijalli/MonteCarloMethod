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
