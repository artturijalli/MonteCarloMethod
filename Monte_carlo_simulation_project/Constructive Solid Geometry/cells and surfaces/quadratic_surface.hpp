#ifndef quadratic_surface_hpp
#define quadratic_surface_hpp

#include <stdio.h>
#include <math.h>

class quadratic_surface {
public:
    float A,B,C,D,E,F,G,H,I,J = 0;
    
    //Default constructor
    quadratic_surface();
    
    // General quadratic surface
    quadratic_surface(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, bool complement);
    
    bool is_complement;
        
    float surface_test(float x, float y, float z);
    float distance_function(float x, float y, float z, float u, float v, float w);
};

class sphere : public quadratic_surface {
    float A = 1;
    float B = 1;
    float C = 1;
public:
    sphere(float x0, float y0, float z0, float r, bool complement);
    float x_0, y_0, z_0, r_;
};

class plane : public quadratic_surface {
public:
    plane(float p0, char axis, bool complement);
    float p_0;
    char axis_;
};

class cylinder : public quadratic_surface {
public:
    cylinder(float x0, float y0, float z0, float r, char axis, bool complement);
    float x_0, y_0, z_0, r_;
    char axis_;
};

#endif /* quadratic_surface_hpp */
