#ifndef global_params_h
#define global_params_h

#include <vector>
#include "quadratic_surface.hpp"
#include "derived_surface.hpp"
#include "cell.hpp"

extern int M;
extern int N;
extern float D_LINES;
extern float L_NEEDLE;
extern float R_CIRCLE;

extern std::vector<quadratic_surface> quadratic_surfaces;
extern std::vector<derived_surface> derived_surfaces;
extern std::vector<cell> cells;

#endif /* global_params_h */
