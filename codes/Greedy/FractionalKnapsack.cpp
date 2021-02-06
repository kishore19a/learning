#include <iostream>
#include <vector>
#include <algorithm>

float maxProfit(std::vector<std::pair<float, float>>& itemsList, float knapsackCapacity)
{
	// sort by ratio (value/weight)
	std::sort(itemsList.begin(), itemsList.end(), [](std::pair<int, int> a, std::pair<int, int> b){
		return((a.second/a.first) > (b.second/b.first));
	});

	int res{0};
	for(auto& item : itemsList)
	{
		if(item.first < knapsackCapacity)
		{
			res += item.second;
			knapsackCapacity -= item.first;
		}
		else
		{
			res += item.second * (knapsackCapacity / item.first);
			return res;
		}
	}
}

void printItems(std::vector<std::pair<float, float>>& itemsList)
{
	for(auto& item : itemsList)
		std::cout << "(" << item.first << ", " << item.second << ")" << std::endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	std::vector<std::pair<float, float>> itemsList = {{50, 600}, {20, 500}, {30, 400}};
	// printItems(itemsList);
	// std::cout << std::endl;

	std::cout << maxProfit(itemsList, 70) << std::endl;
	// std::cout << std::endl;

	// printItems(itemsList);
	// std::cout << std::endl;

	return 0;
}

// g++ -std=c++11 FractionalKnapsack.cpp -o FractionalKnapsack