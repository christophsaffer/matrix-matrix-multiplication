#ifndef MATMAT_HPP
#define MATMAT_HPP

void matmat(double alpha, bool trans,
 	double const* a, int N,
 	double const * b,
 	double beta,
 	double * c);
#endif // MATMAT_HPP