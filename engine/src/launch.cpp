#include "engine/math/vec4/vec4_math.h"

#include <cstdio>
#include <iostream>

int main (int, char**)
{
    using namespace rpf::math;

    vec4::t loc_1 = { 1, 2, 3, 0 };
    vec4::t loc_2 = { 5, 6, 7, 1 };
    vec4::t loc_3 = { 1, 2, 3, 4 };
    vec4::t loc_4 = { 1, 2, 3, 0 };
    vec4::t loc_5 = { 5, 6, 7, 1 };
    vec4::t loc_6 = { 1, 2, 3, 4 };

    printf("Initial Vectors: \n");
    vec4::print_vec4(&loc_1);
    vec4::print_vec4(&loc_2);
    vec4::print_vec4(&loc_3);
    vec4::print_vec4(&loc_4);
    vec4::print_vec4(&loc_5);
    vec4::print_vec4(&loc_6);

    vec4::pair_in loc_input[3]
        {
            { loc_1, loc_2 },
            { loc_3, loc_4 },
            { loc_5, loc_6 }
        };
    vec4::pair_out loc_output[3] {};

    vec4::add(loc_input, 3, loc_output);

    printf("\n\nResults: \n");
    vec4::print_vec4(&loc_output[0].c_);
    vec4::print_vec4(&loc_output[1].c_);
    vec4::print_vec4(&loc_output[2].c_);

    std::cin.get();
}
