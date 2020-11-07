#ifndef neutron_hpp
#define neutron_hpp

#include <stdio.h>

class neutron
{
public:
    neutron();
    ~neutron();

    float energy;
    int pos[3] = {0, 0, 0};
    int dir[3] = {0, 0, 0};
    float time = .0f;
    int generation = 0;

    neutron(float e);
};

#endif /* neutron_hpp */
