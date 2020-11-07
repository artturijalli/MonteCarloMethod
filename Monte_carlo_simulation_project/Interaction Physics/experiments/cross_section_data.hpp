#ifndef cross_section_data_hpp
#define cross_section_data_hpp

#include <stdio.h>
#include "input_reader.hpp"
#include "math_helpers.hpp"

void get_total_cross_section_data(std::string from_file);
void get_radiative_capture_cross_section_data(std::string from_file);
void get_fission_cross_section_data(std::string from_file);
void get_microscopic_inelastic_scattering_cross_section_data(std::string from_file);
void get_water_microscopic_cross_section_data();
void get_natural_uranium_cross_section_data();

void get_asked_cross_section_datasets();


#endif /* cross_section_data_hpp */
