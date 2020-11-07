#include "cross_section_data.hpp"

float water_molar_mass = 18.01528;
float water_density = 1000e3;
float uranium_molar_mass = 0.0072 * 235.04393 + 0.9928 * 238.02891;
float uranium_density = 19050e3;

float n_mol = 6.02214076e23;

float water_molecule_density = (water_density/water_molar_mass) * n_mol;
float uranium_atom_density = (uranium_density/uranium_molar_mass) * n_mol;

float rho_nuc_H1 = 2 * water_molecule_density;
float rho_nuc_O16 = water_molecule_density;
float rho_nuc_U235 = 0.0072 * uranium_atom_density;
float rho_nuc_U238 = 0.9928 * uranium_atom_density;

float barn = 1.0e-28;

std::vector<float> default_energy_range(){
    std::vector<float> E_range = linspace(log(pow(10, -11)), log(20), 500);
    for(int i = 0; i < E_range.size(); i++){
        E_range[i] = exp(E_range[i]);
    }
    return E_range;
}

void get_total_cross_section_data(std::string from_file){
    endf endf_object = endf(from_file + ".txt");
    std::ofstream myfile;
    std::string output_file_name = from_file + "_output.txt";
    myfile.open (output_file_name);
    std::vector<float> E_range = default_energy_range();
    for(int i = 0; i < E_range.size(); i++){
        myfile << E_range[i] << " " << endf_object.cross_section_binary_search(E_range[i], endf_object.MTs) << "\n";
    }
    myfile.close();
}

void get_radiative_capture_cross_section_data(std::string from_file){
    endf endf_object = endf(from_file + ".txt");
    std::ofstream myfile;
    std::string output_file_name = from_file + "radiative_capture_output.txt";
    myfile.open (output_file_name);
    std::vector<float> E_range = default_energy_range();
    for(int i = 0; i < E_range.size(); i++){
        myfile << E_range[i] << " " << endf_object.cross_section_binary_search(E_range[i], { 102 }) << "\n";
    }
    myfile.close();
}

void get_fission_cross_section_data(std::string from_file){
    endf endf_object = endf(from_file + ".txt");
    std::ofstream myfile;
    std::string output_file_name = from_file + "fission_output.txt";
    myfile.open (output_file_name);
    std::vector<float> E_range = default_energy_range();
    std::vector<int> MTs;
    MTs.push_back(18);
    for(int i = 0; i < E_range.size(); i++){
        myfile << E_range[i] << " " << endf_object.cross_section_binary_search(E_range[i], { 18 }) << "\n";
    }
    myfile.close();
}

void get_microscopic_inelastic_scattering_cross_section_data(std::string from_file){
    endf endf_object = endf(from_file + ".txt");
    std::ofstream myfile;
    std::string output_file_name = from_file + "microscopic_inelastic_scattering_output.txt";
    myfile.open (output_file_name);
    std::vector<float> E_range = default_energy_range();
    std::vector<int> MTs;
    MTs.push_back(18);
    for(int i = 0; i < E_range.size(); i++){
        myfile << E_range[i] << " " << endf_object.cross_section_binary_search(E_range[i], range_vector(51, 91, 1)) << "\n";
    }
    myfile.close();
}

void get_water_microscopic_cross_section_data(){
    endf endf_object_H1 = endf("H1.txt");
    endf endf_object_O16 = endf("O16.txt");
    
    std::ofstream myfile;
    std::string output_file_name = "water_output.txt";
    myfile.open (output_file_name);
    std::vector<float> E_range = default_energy_range();
    for(int i = 0; i < E_range.size(); i++){
        myfile << E_range[i] << " " << barn * rho_nuc_H1 * 2.0f * endf_object_H1.cross_section_binary_search(E_range[i], endf_object_H1.MTs) + barn * rho_nuc_O16 * endf_object_H1.cross_section_binary_search(E_range[i], endf_object_O16.MTs) << "\n";
    }
    myfile.close();
}

void get_natural_uranium_cross_section_data(){
    endf endf_object_U235 = endf("U235.txt");
    endf endf_object_U238 = endf("U238.txt");
    
    float r_U235 = 0.0072f;
    float r_U238 = 0.9928f;
    
    std::ofstream myfile;
    std::string output_file_name = "natural_uranium_output.txt";
    myfile.open (output_file_name);
    std::vector<float> E_range = default_energy_range();
    for(int i = 0; i < E_range.size(); i++){
        myfile << E_range[i] << " " << barn * r_U235 * rho_nuc_U235 * endf_object_U235.cross_section_binary_search(E_range[i], endf_object_U235.MTs) + barn * r_U238 * rho_nuc_U238 * endf_object_U238.cross_section_binary_search(E_range[i], endf_object_U238.MTs) << "\n";
    }
    myfile.close();
}

void get_asked_cross_section_datasets(){
    get_total_cross_section_data("H1");
    get_total_cross_section_data("O16");
    get_radiative_capture_cross_section_data("U235");
    get_fission_cross_section_data("U235");
    get_radiative_capture_cross_section_data("U238");
    get_fission_cross_section_data("U238");
    get_microscopic_inelastic_scattering_cross_section_data("U238");
    get_water_microscopic_cross_section_data();
    get_natural_uranium_cross_section_data();
}
