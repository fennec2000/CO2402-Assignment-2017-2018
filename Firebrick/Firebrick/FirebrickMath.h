#pragma once
#include <random>

// returns a random number in the range 0 .. n, inclusive
inline int Random(const float n) { return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * (n + 1)); };