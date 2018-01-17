#ifndef MATMATALL_HPP
#define MATMATALL_HPP

void matmatall(double alpha, bool trans,
 double const* a, int m, int n, int lda,
 double const * b, int k, int ldb,
 double beta,
 double * c, int ldc);

#endif // MATMATALL_HPP