#include <iostream>
#include <algorithm>

void printNumbersFromNTo1(int num)
{
	if(num == 0)
		return;
	else
	{
		std::cout << num << " ";
		printNumbersFromNTo1(num-1);
	}
}

void printNumbersFrom1ToN(int num)
{
	if(num == 0)
		return;
	else
	{
		printNumbersFrom1ToN(num-1);
		std::cout << num << " ";
	}
}

int numberOfRopeCuts(int n, int a, int b, int c)
{
	if(n == 0) return 0;
	if(n < 0) return -1;

	int res = std::max({numberOfRopeCuts(n - a, a, b, c),
						numberOfRopeCuts(n - b, a, b, c),
					    numberOfRopeCuts(n - c, a, b, c)});

	if(res == -1)
		return res;

	return res + 1;
}

int main(int argc, char const *argv[])
{
	int num;
	std::cout << "Enter num: ";
	std::cin >> num;

	printNumbersFromNTo1(num);
	std::cout << std::endl;

	printNumbersFrom1ToN(num);
	std::cout << std::endl;

	int lengthOfRope, a, b, c;
	std::cout << "Enter lengthOfRope, a, b, c" << std::endl;
	std::cin >> lengthOfRope >> a >> b >> c;

	std::cout << "Max number of cuts = " << numberOfRopeCuts(lengthOfRope, a, b, c) << std::endl;

	return 0;
}

// g++ -std=c++11 recursionPractise.cpp -o recursionPractise