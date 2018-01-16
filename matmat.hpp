#ifndef MATMAT_HPP
#define MATMAT_HPP

void matmat(double alpha, bool trans,double const* a, int m, int n, int lda, double const * b, int k, int ldb,double beta, double * c, int ldc);

#endif // MATMAT_HPP