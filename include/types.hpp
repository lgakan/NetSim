//
// Created by ACER on 15.12.2021.
//

#ifndef NETSIM_TYPES_HPP
#define NETSIM_TYPES_HPP

#include <functional>


// The data type used to represent product ID
using ElementID = int;
// Number of half-products in container
using size_type = unsigned long long int;


// The data type used to represent time
using Time = unsigned int;
//The data type used to represent time offset
using TimeOffset = unsigned int;
//Generating random number
using ProbabilityGenerator = std::function<double()>;

#endif //NETSIM_TYPES_HPP
