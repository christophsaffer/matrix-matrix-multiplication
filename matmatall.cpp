#include "matmatall.hpp"

#include <iostream>
#include <vector>

void matmatall(double alpha, double const* a, int M, int N, double const* b, int K, double beta, double* c){

#pragma omp parallel for
	for (int j=0; j < M; ++j){
		for (int k=0; k < K; ++k) {
			c[j * K + k] *= beta;
			for (int i=0; i < N; ++i) {
				c[j * K + k] += alpha * a[j * N + i] * b[i * K + k];
			}
		}
	}
}
