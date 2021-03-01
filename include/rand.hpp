#ifndef RAND_HPP
#define RAND_HPP

#include <random>

std::random_device rd;
std::mt19937 mersenne(rd());

#endif /* RAND_HPP */
