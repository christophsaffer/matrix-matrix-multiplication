#include "matmat.hpp"

#include <iostream>
#include <sstream>
#include <chrono>
#include <vector>
#include <random>

int main (int argc, char** argv) {

	double alpha = 2;
	double beta = 0;
	int n = 2;
	double a[n*n] __attribute__((aligned(64)));
	double b[n*n] __attribute__((aligned(64)));
	double c[n*n] __attribute__((aligned(64)));

	for(int i=0; i < n*n; ++i){
		a[i] = i+1;
		b[i] = -i-1;
		c[i] = 2;
	}

	matmat(alpha, false, a, n, b, beta, c);

	double d = 0;
	for (int i=0; i < n*n; ++i){
		std::cout << c[i] << '\n';
	}

	if (d != 943) {
		return -1;
	}
	else {

	  	int N;
	  	std::istringstream inbuf(argv[1]);
	  	inbuf >> N;

	  	// Initialize random number generator
		std::mt19937 gen(std::random_device{}());
	 	std::uniform_real_distribution<> dis(0, 1);

	 	// Initialize scalars alpha, beta and matrices a, b, c
	 	double const alpha = dis(gen);
		// std::vector<double> a(N*N);
		// std::vector<double> b(N*N);
		double const beta = dis(gen);
		// std::vector<double> c(N*N);

		double a[N*N] __attribute__((aligned(64)));
		double b[N*N] __attribute__((aligned(64)));
		double c[N*N] __attribute__((aligned(64)));

		for(int i=0; i < N*N; ++i){
			a[i] = dis(gen);
			b[i] = dis(gen);
			c[i] = 0;
		}

		matmat(alpha, false, a, N, b, beta, c);

		std::cout << "Runs correctly, N: " << N << '\n';
		return 0;
	}
}