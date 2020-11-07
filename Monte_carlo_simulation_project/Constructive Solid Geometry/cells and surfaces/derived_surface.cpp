#include "derived_surface.hpp"

derived_surface::derived_surface(){}

float derived_surface::surface_test(float x, float y, float z){
    float eps = .0001f;
    float s = -1;
    auto len = quadratic_surfaces.size();
    for(int i = 0; i < len; ++i){
        if(quadratic_surfaces[i].surface_test(x, y, z) > eps){
            s = 1;
        }
    }
    return is_complement ? -s : s;
}

float derived_surface::distance_function(float x, float y, float z, float u, float v, float w){
    std::vector<float> distances;
    for (int i = 0; i < quadratic_surfaces.size(); ++i) {
        distances.push_back(quadratic_surfaces[i].distance_function(x, y, z, u, v, w));
    }
    
    float MAX_D = std::numeric_limits<float>::max();
    float distance = MAX_D;

    for (int i = 0; i < quadratic_surfaces.size(); ++i) {
        if ((distances[i] > 0) && (surface_test(x + distances[i] * u, distances[i] * v, z + distances[i] * w) < 0) && distances[i] < distance)
            distance = distances[i];
    }
    
    return distance == MAX_D ? -1 : distance;
}

truncated_cylinder::truncated_cylinder(cylinder cylinder, plane plane_1, plane plane_2, bool complemented){
    plane_1.p_0 < plane_2.p_0 ? plane_1.is_complement = true : plane_2.is_complement = true;
    
    quadratic_surfaces.push_back(cylinder);
    quadratic_surfaces.push_back(plane_1);
    quadratic_surfaces.push_back(plane_2);
    
    is_complement = complemented;
}

cuboid::cuboid(plane plane_1, plane plane_2, plane plane_3, plane plane_4, plane plane_5, plane plane_6, bool complemented){
    plane_1.p_0 < plane_2.p_0 ? plane_1.is_complement = true : plane_2.is_complement = true;
    plane_3.p_0 < plane_4.p_0 ? plane_3.is_complement = true : plane_4.is_complement = true;
    plane_5.p_0 < plane_6.p_0 ? plane_5.is_complement = true : plane_6.is_complement = true;
    
    quadratic_surfaces.push_back(plane_1);
    quadratic_surfaces.push_back(plane_2);
    quadratic_surfaces.push_back(plane_3);
    quadratic_surfaces.push_back(plane_4);
    quadratic_surfaces.push_back(plane_5);
    quadratic_surfaces.push_back(plane_6);
    
    is_complement = complemented;
}



infinite_square_prism::infinite_square_prism(plane plane_1, plane plane_2, plane plane_3, plane plane_4, bool complemented){
    plane_1.p_0 < plane_2.p_0 ? plane_1.is_complement = true : plane_2.is_complement = true;
    plane_3.p_0 < plane_4.p_0 ? plane_3.is_complement = true : plane_4.is_complement = true;
    
    quadratic_surfaces.push_back(plane_1);
    quadratic_surfaces.push_back(plane_2);
    quadratic_surfaces.push_back(plane_3);
    quadratic_surfaces.push_back(plane_4);
    
    is_complement = complemented;
}
