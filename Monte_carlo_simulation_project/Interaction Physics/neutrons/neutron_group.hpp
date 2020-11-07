#ifndef neutron_group_hpp
#define neutron_group_hpp

#include <stdio.h>

#include "endf.hpp"
#include "neutron.hpp"
#include "maxwell.hpp"

class neutron_group
{
public:
    neutron_group();
    ~neutron_group();

    neutron_group(float e, int amount);

    std::vector<endf> medium;
    std::vector<float> consentrations;

    std::vector<neutron> primary_neutrons;
    std::vector<neutron> secondary_neutrons;

    float velocity(float energy);

    void react(float energy);
    int sample_nuclide(float energy);

    void capture(std::vector<neutron> &n);
    void fission(float T, endf nuclide, std::vector<neutron> &n);
    void scattering(float T, std::vector<neutron> &n);
};

int binary_search_index(float target, std::vector<float> vec);

#endif /* neutron_group_hpp */
