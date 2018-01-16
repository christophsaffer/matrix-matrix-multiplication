#include "matmat.hpp"

#include <iostream>
#include <vector>

void matmat(double alpha, bool trans,
 	double const* a, int N,
 	double const* b,
 	double beta,
 	double* c){

	double d = 0;

	for(int i=0; i < N; ++i){
		for(int j=0; j < N; ++j){
			d = 0;
			for(int k=0; k < N; ++k){
				d += alpha * a[k + N * j] * b[j + N * k];
			}
			c[i + N * j] = d + beta * c[i + N * j];
		}
	}

}