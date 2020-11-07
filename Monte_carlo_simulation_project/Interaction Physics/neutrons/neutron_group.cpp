#include "neutron_group.hpp"

neutron_group::neutron_group(){}
neutron_group::~neutron_group(){}

neutron_group::neutron_group(float e, int amount){
    for (int i = 0; i < amount; i++) {
        primary_neutrons.push_back(neutron(e));
    }
}

float neutron_group::velocity(float energy){
    return 437 * sqrt(energy);
}

void neutron_group::react(float energy){
    int nuclide_index = sample_nuclide(energy);

    float r = ((float)rand() / (RAND_MAX));
    std::vector<float> cross_sections;

    std::vector<int> capture_indices = {102, 103, 104, 105, 106, 107};
    cross_sections.push_back(medium[nuclide_index].cross_section_binary_search(energy, capture_indices));

    std::vector<int> fission_indices = {18};
    cross_sections.push_back(cross_sections[0] + medium[nuclide_index].cross_section_binary_search(energy, fission_indices));

    std::vector<int> scattering_indices;
    for (int i = 51; i < 92; i++) scattering_indices.push_back(i);
    cross_sections.push_back(cross_sections[1] + medium[nuclide_index].cross_section_binary_search(energy, scattering_indices));

    float target = cross_sections[2] * r;

    int reaction_index = binary_search_index(target, cross_sections);

    std::vector<neutron> &n = primary_neutrons;

    if (reaction_index == 0) {
        capture(n);
    }
    else if (reaction_index == 1) {
        fission(medium[nuclide_index].T, medium[nuclide_index],n);
    }
    else if (reaction_index == 2) {
        scattering(medium[nuclide_index].T,n);
    }
}

int neutron_group::sample_nuclide(float energy){
    float r = ((float)rand() / (RAND_MAX));
    std::vector<float> macroscopic_cross_sections = {.0f};
    for (int i = 0; i < consentrations.size(); i++) {
        macroscopic_cross_sections.push_back(macroscopic_cross_sections[i] + medium[i].cross_section_binary_search(energy, medium[i].MTs) * consentrations[i]);
    }

    float target = macroscopic_cross_sections[consentrations.size()] * r;
    int idx = binary_search_index(target, macroscopic_cross_sections);

    return idx - 1;
}

void neutron_group::capture(std::vector<neutron> &n){
    n.pop_back();
}


void neutron_group::fission(float T, endf nuclide, std::vector<neutron> &n){
    n.pop_back();

    float E = maxwell_sample(T);
    int index = binary_search_index(E, nuclide.energies);
    float nubar = ((nuclide.nubars[index] - nuclide.nubars[index-1]) / (nuclide.energies[index] - nuclide.energies[index - 1])) * (E - nuclide.energies[index - 1]) + nuclide.nubars[index - 1];

    int nu = floor(nubar);
    float r = ((float)rand() / (RAND_MAX));
    if (r < nubar - nu) nu += 1;

    for (int i = 0; i < nu; i++) {
        secondary_neutrons.push_back(neutron(maxwell_fission_spectrum(1,E,T)));
    }
}

void neutron_group::scattering(float T, std::vector<neutron> &n){ /*ToDo*/ }

int binary_search_index(float target, std::vector<float> vec){
    int left = 0;
    auto right = vec.size() - 1;
    int n = roundf((left + right) / 2);
    
    if (target < vec[right] && target > vec[left]) {
        while (!(vec[n-1] <= target && target < vec[n])) {
            if (vec[n] < target) {
                left = n+1;
            }
            else if (target < vec[n]) {
                right = n-1;
            }
            n = roundf((left + right) / 2);
        }
    }
    else if (target >= vec[right] || target <= vec[left]) {
        printf("Bin search returning -1");
        return -1;
    }
    return n;
}

