#ifndef MATMATALL_HPP
#define MATMATALL_HPP

#include <vector>
#include <boost/align/aligned_allocator.hpp>

template <typename T>
using aligned_allocator = boost::alignment::aligned_allocator<T, 64>;
template <typename T>
using aligned_vector = std::vector<T, aligned_allocator<T>>;

void matmatall(double alpha, double const* a, int m, int n, double const* b, int k, double beta, double * c);

#endif // MATMATALL_HPP