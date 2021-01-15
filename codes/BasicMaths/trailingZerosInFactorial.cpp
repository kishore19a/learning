#include <iostream>
#include <cmath>
#include <chrono>
#include <iomanip>

// Naive coding method: much more time complexity
int trailingZeros(int number)
{
	int iterationNumber{1}, divisibilityCount{0}, trailingZero{0};

	do
	{
		int power5 = std::pow(5, iterationNumber);
		int count{0};
		for(int i = 1; i <= number; i++)
		{
			if(i % power5 == 0) count++;
		}
		trailingZero += count;
		iterationNumber++;
		divisibilityCount = count;		
	}
	while(divisibilityCount != 0);

	return trailingZero;
}

int trailingZerosBetter(int number)
{
	int trailingZero{0};

	for(int i = 5; i <= number; i *= 5)
		trailingZero += number / i;

	return trailingZero;
}

int main(int argc, char const *argv[])
{
	int number;

	std::cout << "Enter number whose factorial's trailing zero needs to be calculated: ";
	std::cin >> number;

	auto start = std::chrono::high_resolution_clock::now();
	std::cout << "Number of trailing zeros in " << number << "! = " << trailingZeros(number) << std::endl;
	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elasped = end1 - start;
	std::cout << std::fixed << std::setprecision(10) << "Time taken in naive method = " << elasped.count() << " seconds " << std::endl;
	std::cout << "Number of trailing zeros in " << number << "! = " << trailingZerosBetter(number) << std::endl;
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elasped2 = end2 - end1;
	std::cout << std::fixed << std::setprecision(10) << "Time taken in better method = " << elasped2.count() << " seconds " << std::endl;

	return 0;
}

// g++ -std=c++11 trailingZerosInFactorial.cpp -o trailingZerosInFactorial