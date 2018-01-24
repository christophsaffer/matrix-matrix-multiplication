#include "matmat.hpp"
#include "matmatall.hpp"

#include <iostream>
#include <sstream>
#include <chrono>
#include <vector>
#include <random>

using std::chrono::system_clock;
using std::chrono::duration;

int main (int argc, char** argv) {
	//if (testcase_matmatall() == 1){
	if (true) {

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

	//  	//Initialize random number generator
	//	std::mt19937 gen(std::random_device{}());
	// 	std::uniform_real_distribution<> dis(0, 1);

	 	// Initialize scalars alpha, beta and matrices a, b, c
	 	double const alpha = 0.9; //dis(gen);
		double const beta = 0.9; //dis(gen);
		aligned_vector<double> a(M*N);
		aligned_vector<double> b(N*K);
		aligned_vector<double> c(M*K);

		// Start time measuring
		auto start = system_clock::now();

		for (int i=0; i < L; ++i) {
			matmatall(alpha, a.data(), M, N, b.data(), K, beta, c.data());
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