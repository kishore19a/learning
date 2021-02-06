#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

float maxProfit(std::vector<std::pair<int, float>>& jobsList)
{
	auto it = std::max_element(jobsList.begin(), jobsList.end(), [](std::pair<int, float> a, std::pair<int, float> b){
		return (a.first < b.first);
	});

	if (it == jobsList.end()) throw "max_element called on emtpy vector";
	auto max = *it;

	std::cout << max.first << std::endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	std::vector<std::pair<int, float>> jobsList = {{2, 100}, {1, 50}, {2, 10}, {1, 20}, {3, 30}};
	// maxProfit(jobsList);
	return 0;
}

// g++ -std=c++11 JobSelection.cpp -o JobSelection