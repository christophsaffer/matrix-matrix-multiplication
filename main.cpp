#include "matmat.hpp"

#include <iostream>
#include <sstream>
#include <chrono>
#include <vector>
#include <random>

using std::chrono::system_clock;
using std::chrono::duration;

int testcase (){

	double alpha = 2;
	double beta = 0.5;
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
		d += c[i];
	}

	if (d == -104) {
		return 1;
	}
	else {
		return -1;
	}

}


int main (int argc, char** argv) {
	if (testcase() == 1){

	  	int N;
	  	std::istringstream inbuf1(argv[1]);
	  	inbuf1 >> N;

	  	int M;
	  	std::istringstream inbuf2(argv[2]);
	  	inbuf2 >> M;

	  	int const al = 16;

	  	// Initialize random number generator
		std::mt19937 gen(std::random_device{}());
	 	std::uniform_real_distribution<> dis(0, 1);

	 	// Initialize scalars alpha, beta and matrices a, b, c
	 	double const alpha = dis(gen);
		double const beta = dis(gen);
		double a[N*N] __attribute__((aligned(al)));
		double b[N*N] __attribute__((aligned(al)));
		double c[N*N] __attribute__((aligned(al)));

		for(int i=0; i < N*N; ++i){
			a[i] = dis(gen);
			b[i] = dis(gen);
			c[i] = dis(gen);
		}
		// Start time measuring
		auto start = system_clock::now();

		for (int i=0; i < M; ++i) {
			matmat(alpha, false, a, N, b, beta, c);
		}
	
		// Time measuring output
 		auto end = system_clock::now();
 		const double elapsed_seconds = duration<double>(end - start).count();
		std::cout << "Duration: " << elapsed_seconds << "s" << std::endl;

		return 0;
	}
	else {
		return -1;
	}
}	