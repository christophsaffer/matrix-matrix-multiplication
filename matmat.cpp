#include "matmat.hpp"

#include <iostream>
#include <vector>

void matmat(double alpha, bool trans,
 	double const* a, int N,
 	double const* b,
 	double beta,
 	double* c){

	for (int j=0; j < N; ++j){
		for (int k=0; k < N; ++k) {
			c[j * N + k] *= beta;
			for (int i=0; i < N; ++i) {
				c[j * N + k] += alpha * a[j * N + i] * b[i * N + k];
			}
		}
	}

}
