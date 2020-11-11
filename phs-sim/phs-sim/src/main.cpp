#include <iostream>
#include <time.h>
#include <chrono>
#include <ctime>  
float A = 90;
float M = 5;
float COF = 1.6;
float FOF;
float F = 100;
float D = 2;
float r = 0;
float dt = 1;

int main()
{
	while (1)
	{
		auto L = std::chrono::high_resolution_clock::now();
		FOF = COF * (M * 9.8);
		float CF = F - FOF;
		float AV = (F * D * sinf(A)) / (M * (D * D));
		r += AV * 0.00001;
		std::cout << r << std::endl;
		auto N = std::chrono::high_resolution_clock::now();
		float dt = (N - L)
	}
}