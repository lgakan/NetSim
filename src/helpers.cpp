#include "helpers.hpp"

#include <cstdlib>
#include <random>

// Generating high quality pseudorandom numbers with for example Mersenne Twister algorithm
// look. https://en.cppreference.com/w/cpp/numeric/random
std::random_device rd;
std::mt19937 rng(rd());

double default_probability_generator() {
    //Generate pseudo-random numbers from the interval [0, 1); 10 randomness bits.
    return std::generate_canonical<double, 10>(rng);
}

std::function<double()> probability_generator = default_probability_generator;
