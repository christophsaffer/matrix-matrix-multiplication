#include "matmatall.hpp"

#include <iostream>
#include <vector>

void matmatall(double alpha, bool trans,
 	double const* a, int M, int N, int lda,
 	double const * b, int K, int ldb,
 	double beta,
 	double * c, int ldc){

	for (int j=0; j < M; ++j){
		for (int k=0; k < K; ++k) {
			c[j * K + k] *= beta;
			for (int i=0; i < N; ++i) {
				c[j * K + k] += alpha * a[j * N + i] * b[i * K + k];
			}
		}
	}
}
