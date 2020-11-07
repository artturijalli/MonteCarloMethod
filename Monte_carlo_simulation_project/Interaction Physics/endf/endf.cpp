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

float endf::cross_section_binary_search(float E, std::vector<int> MT_numbers)
{
    float sigma = 0;
    auto MTs_length = MT_numbers.size();
    
    for (int i = 0; i < MTs_length; i++) {
        int MT = MT_numbers[i];
        int index = get_index(MTs, MT);
        if (index != -1) {
            std::vector<float> energies = cross_section_energies[index];
            std::vector<float> sigmas = cross_sections[index];
            
            int start = 0;
            auto end = energies.size() - 1;
            int mid = roundf((start + end) / 2);
            
            if (E <= energies[end] && E >= energies[0]) {
                while (!(energies[mid] == E || (energies[mid] <= E && E < energies[mid + 1]))) {
                    energies[mid] < E ? start = mid + 1 : end = mid - 1;
                    mid = roundf((start + end) / 2);
                }
                energies[mid] == E ? sigma += sigmas[mid] : sigma += ((sigmas[mid + 1] - sigmas[mid]) / (energies[mid + 1] - energies[mid])) * (E - energies[mid]) + sigmas[mid];
            }
            else if (E > energies[end]) {
                sigma += sigmas[end];
            }
            else if (E < energies[0]) {
                sigma += sigmas[0];
            }
        }
    }
    return sigma;
}
