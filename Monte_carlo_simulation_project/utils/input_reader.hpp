//
//  input_reader.hpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 7.10.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#ifndef input_reader_hpp
#define input_reader_hpp

#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>

#include "quadratic_surface.hpp"
#include "derived_surface.hpp"
#include "cell.hpp"
#include "global_params.hpp"

void read_params();

sphere create_sphere();
plane create_plane();
cylinder create_cylinder();

void read_next_surface_params(std::fstream& myfile, std::string& a);

quadratic_surface create_quadratic_surface();
quadratic_surface read_next_quadratic_surface(std::fstream& myfile, std::string& a);

truncated_cylinder read_truncated_cylinder(std::fstream& myfile, std::string& a);
cuboid read_cuboid(std::fstream& myfile, std::string& a);
infinite_square_prism read_infinite_square_prism(std::fstream& myfile, std::string& a);

derived_surface read_next_derived_surface(std::fstream& myfile, std::string& a);
cell read_next_cell(std::fstream& myfile, std::string& a);
void read_surfaces(std::string file_name);
#endif /* input_reader_hpp */
