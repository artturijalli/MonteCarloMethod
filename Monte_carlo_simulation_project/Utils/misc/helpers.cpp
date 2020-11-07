#include "helpers.hpp"

int get_index(std::vector<int> input_vector, int value)
{
    auto iterator = find(input_vector.begin(), input_vector.end(), value);
    return iterator != input_vector.end() ? iterator - input_vector.begin() : -1;
}

void print_vector(std::vector<float> vec)
{
    std::cout << "size: " << vec.size() << std::endl;
    for (float d : vec)
        std::cout << d << " ";
        std::cout << std::endl;
}

std::vector<int> range_vector(int start, int end, int interval){
    std::vector<int> myVec;
    for( int i = start; i <= end; i += interval )
        myVec.push_back( i );
    return myVec;
}

