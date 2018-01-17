#include "matmat.hpp"
#include "matmatall.hpp"

#include <iostream>
#include <sstream>
#include <chrono>
#include <vector>
#include <random>

using std::chrono::system_clock;
using std::chrono::duration;

int testcase_matmat (){

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

int testcase_matmatall (){

	double alpha = 2;
	double beta = 2;
	int M = 3;
	int N = 2;
	int K = 4;
	double a[M * N] __attribute__((aligned(64)));
	double b[N * K] __attribute__((aligned(64)));
	double c[M * K] __attribute__((aligned(64)));

	for(int i=0; i < 6; ++i){
		a[i] = i+1;
	}
	for(int i=0; i < 8; ++i){
		b[i] = -i-1;
	}
	for(int i=0; i < 12; ++i){
		c[i] = 1;
	}

	matmatall(alpha, false, a, M, N, 0, b, K, 0, beta, c, 0);

	double d = 0;
	for (int i=0; i < M * K; ++i){
		d += c[i];
		// if (i%4 == 0) {
		// 	std::cout << '\n';
		// }
		// std::cout << c[i] << " ";
	}
	std::cout << '\n';

	if (d == -780) {
		return 1;
	}
	else {
		return -1;
	}
}


int main (int argc, char** argv) {
	if (testcase_matmatall() == 1){

	  	int M;
	  	std::istringstream inbuf1(argv[1]);
	  	inbuf1 >> M;

	  	int N;
	  	std::istringstream inbuf2(argv[2]);
	  	inbuf2 >> N;

	  	int K;
	  	std::istringstream inbuf3(argv[3]);
	  	inbuf3 >> K;

	  	int L = 500;

	  	int const al = 32;

	  	// Initialize random number generator
		std::mt19937 gen(std::random_device{}());
	 	std::uniform_real_distribution<> dis(0, 1);

	 	// Initialize scalars alpha, beta and matrices a, b, c
	 	double const alpha = dis(gen);
		double const beta = dis(gen);
		double a[M*N] __attribute__((aligned(al)));
		double b[N*K] __attribute__((aligned(al)));
		double c[M*K] __attribute__((aligned(al)));

		for(int i=0; i < M*N; ++i){
			a[i] = dis(gen);
		}
		for(int i=0; i < N*K; ++i){
			b[i] = dis(gen);
		}
		for(int i=0; i < M*K; ++i){
			c[i] = dis(gen);
		}

		// Start time measuring
		auto start = system_clock::now();

		for (int i=0; i < L; ++i) {
			matmatall(alpha, false, a, M, N, 0, b, K, 0, beta, c, 0);
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