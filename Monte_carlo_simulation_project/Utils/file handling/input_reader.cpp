#include "input_reader.hpp"

int M;
int N;
float D_LINES;
float L_NEEDLE;
float R_CIRCLE;

std::string primitive;
char axis;
float x_0;
float y_0;
float z_0;
float r;

bool is_complement;
bool derived_is_compement;

std::vector<quadratic_surface> quadratic_surfaces;
std::vector<derived_surface> derived_surfaces;
std::vector<cell> cells;

std::vector<std::string> split_words(std::string str) {
    std::stringstream s(str);
    std::vector<std::string> segments;
    std::string word;
    while (s >> word)
    {
        segments.push_back(word);
    }
    return segments;
}


void read_params(){
    std::fstream myfile("params.txt", std::ios_base::in);
    std::string a;
    myfile >> a >> M >> a >> N >> a >> D_LINES >> a >> L_NEEDLE >> a >> R_CIRCLE;
}

sphere create_sphere(){
    return sphere(x_0, y_0, z_0, r, is_complement);
};

plane create_plane(){
    if(axis == 'x'){
        return plane(x_0, axis, is_complement);
    }else if(axis == 'y'){
        return plane(y_0, axis, is_complement);
    }else{
        return plane(z_0, axis, is_complement);
    }
}

cylinder create_cylinder(){
    if(axis == 'x'){
        return cylinder(x_0, y_0, z_0, r, axis, is_complement);
    }else if(axis == 'y'){
        return cylinder(x_0, y_0, z_0, r, axis, is_complement);
    }else{
        return cylinder(x_0, y_0, z_0, r, axis, is_complement);
    }
}

quadratic_surface create_quadratic_surface(){
    if(!primitive.compare("sphere")){
        return create_sphere();
    }else if(!primitive.compare("plane")){
        return create_plane();
    }else if(!primitive.compare("cylinder")){
        return create_cylinder();
    }
    return quadratic_surface();
}

void read_next_surface_params(std::fstream& myfile, std::string& a){
    myfile >> primitive;
    myfile >> a;
    myfile >> is_complement;
    is_complement = is_complement != 0;
    myfile >> a;
    myfile >> axis;
    myfile >> a;
    myfile >> x_0;
    myfile >> a;
    myfile >> y_0;
    myfile >> a;
    myfile >> z_0;
    myfile >> a;
    myfile >> r;
}

quadratic_surface read_next_quadratic_surface(std::fstream& myfile, std::string& a){
    read_next_surface_params(myfile, a);
    return create_quadratic_surface();
}

truncated_cylinder read_truncated_cylinder(std::fstream& myfile, std::string& a){
    read_next_surface_params(myfile, a);
    cylinder cylinder = create_cylinder();
    myfile >> a;
    read_next_surface_params(myfile, a);
    plane plane_1 = create_plane();
    myfile >> a;
    read_next_surface_params(myfile, a);
    plane plane_2 = create_plane();
    return truncated_cylinder(cylinder, plane_1, plane_2, derived_is_compement);
}

cuboid read_cuboid(std::fstream& myfile, std::string& a){
    read_next_surface_params(myfile, a);
    plane plane_1 = create_plane();
    myfile >> a;
    read_next_surface_params(myfile, a);
    plane plane_2 = create_plane();
    myfile >> a;
    read_next_surface_params(myfile, a);
    plane plane_3 = create_plane();
    myfile >> a;
    read_next_surface_params(myfile, a);
    plane plane_4 = create_plane();
    myfile >> a;
    read_next_surface_params(myfile, a);
    plane plane_5 = create_plane();
    myfile >> a;
    read_next_surface_params(myfile, a);
    plane plane_6 = create_plane();
    return cuboid(plane_1, plane_2, plane_3, plane_4, plane_5, plane_6, derived_is_compement);
}

infinite_square_prism read_infinite_square_prism(std::fstream& myfile, std::string& a){
    read_next_surface_params(myfile, a);
    plane plane_1 = create_plane();
    myfile >> a;
    read_next_surface_params(myfile, a);
    plane plane_2 = create_plane();
    myfile >> a;
    read_next_surface_params(myfile, a);
    plane plane_3 = create_plane();
    myfile >> a;
    read_next_surface_params(myfile, a);
    plane plane_4 = create_plane();
    return infinite_square_prism(plane_1, plane_2, plane_3, plane_4, derived_is_compement);
}

derived_surface read_next_derived_surface(std::fstream& myfile, std::string& a){
    std::string derived_type;
    myfile >> derived_type;
    myfile >> a;
    myfile >> derived_is_compement;
    derived_surface surface;
    while(myfile >> a){
        if(!derived_type.compare("truncated_cylinder")){
            return read_truncated_cylinder(myfile, a);
        }else if(!derived_type.compare("cuboid")){
            return read_cuboid(myfile, a);
        }else if(!derived_type.compare("infinite_square_prism")){
            return read_infinite_square_prism(myfile, a);
        }else if(!a.compare("type")){
            surface.quadratic_surfaces.push_back(read_next_quadratic_surface(myfile, a));
        }else if(!a.compare("end_derived")){
            surface.is_complement = derived_is_compement != 0;
            return surface;
        }
    }
    return surface;
}

cell read_next_cell(std::fstream& myfile, std::string& a){
    cell input_cell;
    myfile >> a;
    while(myfile >> a){
        if(!a.compare("type")){
            input_cell.quadratic_surfaces.push_back(read_next_quadratic_surface(myfile, a));
        }else if(!a.compare("derived_type")){
            input_cell.derived_surfaces.push_back(read_next_derived_surface(myfile, a));
        }else if(!a.compare("end_cell")){
            return input_cell;
        }
    }
    return input_cell;
}

void read_surfaces(std::string file_name){
    std::fstream myfile(file_name, std::ios_base::in);
    std::string key;
    while(myfile >> key){
        if(!key.compare("type")){
            quadratic_surfaces.push_back(read_next_quadratic_surface(myfile, key));
        }else if(!key.compare("derived_type")){
            derived_surfaces.push_back(read_next_derived_surface(myfile, key));
        }else if(!key.compare("cell")){
            cells.push_back(read_next_cell(myfile, key));
        }
    }
}

void load_cross_section_data(std::string file_name, endf &endf) {
    std::string line;
    std::ifstream file;
    file.open(file_name);
    if (file.is_open()) {
        getline(file, line);
        std::vector<std::string> w = split_words(line);
        endf.symbol = w[0];
        endf.Z = std::stoi(w[1]);
        endf.A = std::stoi(w[2]);
        endf.AW = std::stof(w[3]);
        endf.T = std::stof(w[4]);

        getline(file, line);
        w = split_words(line);
        endf.NNU = std::stof(w[0]);

        for (int i = 0; i < endf.NNU; i++) {
            getline(file, line);
            w = split_words(line);
            endf.energies.push_back(std::stof(w[0]));
            endf.nubars.push_back(std::stof(w[1]));
        }

        int j = 0;
        while (getline(file, line)) {
            w = split_words(line);
            endf.MTs.push_back(std::stoi(w[0]));
            endf.Qs.push_back(std::stof(w[1]));
            endf.NEs.push_back(std::stoi(w[2]));

            std::vector<float> cs_energies;
            std::vector<float> cross_sections;
            endf.cross_section_energies.push_back(cs_energies);
            endf.cross_sections.push_back(cross_sections);

            for (int i = 0; i < endf.NEs[j]; i++) {
                getline(file, line);
                w = split_words(line);
                endf.cross_section_energies[j].push_back(std::stof(w[0]));
                endf.cross_sections[j].push_back(std::stod(w[1]));
            }
            j++;
        }
    }
}
