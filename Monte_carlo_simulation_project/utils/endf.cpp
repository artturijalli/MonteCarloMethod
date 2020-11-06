//
//  endf.cpp
//  Monte_carlo_simulation_project
//
//  Created by Artturi Jalli on 6.11.2020.
//  Copyright © 2020 Artturi Jalli. All rights reserved.
//

#include "endf.hpp"
#include "input_reader.hpp"

endf::endf()
{
}

endf::~endf()
{
}

endf::endf(std::string file_name)
{
    load_cross_section_data(file_name, *this);
}

float endf::cross_section(float E, std::vector<int> MT_numbers)
{
    float sigma = 0;

    auto len = MT_numbers.size();
    for (int i = 0; i < len; i++) {
        int MT = MT_numbers[i];
        int index = get_index(MTs, MT);
        if (index != -1) {
            std::vector<float> E_vec = cross_section_energies[index];
            std::vector<float> sigma_vec = cross_sections[index];

            int left = 0;
            auto right = E_vec.size();

            int j = roundf((left+right)/2);

            if (E <= E_vec[right] && E >= E_vec[0]) {

                while (!(E_vec[j] == E || (E_vec[j] <= E && E < E_vec[j + 1]))) {
                    if (E_vec[j] < E) {
                        left = j + 1;
                    }
                    else if (E < E_vec[j]) {
                        right = j - 1;
                    }
                    j = roundf((left + right) / 2);
                }

                if (E_vec[j] == E) {
                    sigma = sigma + sigma_vec[j];
                }
                else {
                    sigma = sigma + ((sigma_vec[j + 1] - sigma_vec[j]) / (E_vec[j + 1] - E_vec[j])) * (E - E_vec[j]) + sigma_vec[j];
                }
            }
            else if (E > E_vec[right]) {
                sigma = sigma + sigma_vec[right];
            }
            else if (E < E_vec[0]) {
                sigma = sigma + sigma_vec[0];
            }
        }
        
    }
    return sigma;
}
