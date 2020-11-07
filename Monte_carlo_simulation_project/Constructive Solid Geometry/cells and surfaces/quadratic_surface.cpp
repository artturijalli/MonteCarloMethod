#include "quadratic_surface.hpp"

quadratic_surface::quadratic_surface(){
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    E = 0;
    F = 0;
    G = 0;
    H = 0;
    I = 0;
    J = 0;
    is_complement = false;
}

quadratic_surface::quadratic_surface(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, bool complement){
    A = a;
    B = b;
    C = c;
    D = d;
    E = e;
    F = f;
    G = g;
    H = h;
    I = i;
    J = j;
    is_complement = complement;
}

float quadratic_surface::surface_test(float x, float y, float z){
    float s = A*x*x + B*y*y + C*z*z + D*x*y + E*y*z + F*z*x + G*x + H*y + I*z + J;
    return is_complement ? -s : s;
}

float quadratic_surface::distance_function(float x, float y, float z, float u, float v, float w){
    float K = A*x*x + B*y*y + C*z*z + D*x*y + E*y*z + F*z*x + G*x + H*y + I*z + J;
    float L = 2*(A*u*x + B*v*y + C*w*z) + D*(v*x + u*y) + E*(w*y + v*z) + F*(w*x + u*z) + G*u + H*v + I*w;
    float M = A*u*u + B*v*v + C*w*w + D*u*v + E*v*w + F*u*w;
    
    float D = L*L - 4*M*K;
    if(D < 0){
        return -1;
    }
    
    float d_plus = (-L + sqrt(D)) / (2 * M);
    float d_minus = (-L - sqrt(D)) / (2 * M);
    
    if(d_plus > 0 && d_minus > 0){
        return fmin(d_plus, d_minus);
    } else if(d_plus > 0 && d_minus < 0){
        return d_plus;
    } else if(d_plus < 0 && d_minus > 0){
        return d_minus;
    } else return -1;
}

sphere::sphere(float x0, float y0, float z0, float r, bool complement){
    A = 1;
    B = 1;
    C = 1;
    G = -2*x0;
    H = -2*y0;
    I = -2*z0;
    J = x0 * x0 + y0 * y0 + z0 * z0 + r * r;
    
    x_0 = x0;
    y_0 = y0;
    z_0 = z0;
    r_ = r;
    
    is_complement = complement;
}

plane::plane(float p0, char axis, bool complement){
    if(axis == 'x'){
        G = 1;
        J = -p0;
    }else if(axis == 'y'){
        H = 1;
        J = -p0;
    }else if(axis == 'z'){
        I = 1;
        J = -p0;
    }
    
    p_0 = p0;
    axis_ = axis;
    
    is_complement = complement;
}

cylinder::cylinder(float x0, float y0, float z0, float r, char axis, bool complement)
{
    if (axis == 'x') {
        A = 0;
        B = 1;
        C = 1;

        G = 0;
        H = -2 * y0;
        I = -2 * z0;
        J = y0 * y0 + z0 * z0 - r * r;
    }
    else if (axis == 'y') {
        A = 1;
        B = 0;
        C = 1;

        G = -2 * x0;
        H = 0;
        I = -2 * z0;
        J = x0 * x0 + z0 * z0 - r * r;
    }
    else if (axis == 'z') {
        A = 1;
        B = 1;
        C = 0;
        
        G = -2 * x0;
        H = -2 * y0;
        I = 0;
        J = x0 * x0 + y0 * y0 - r * r;
    }
    D = 0;
    E = 0;
    F = 0;
    
    x_0 = x0;
    y_0 = y0;
    z_0 = z0;
    r_ = r;
    axis_ = axis;
    
    is_complement = complement;
}
