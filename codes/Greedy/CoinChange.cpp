#include <iostream>
#include <cmath>
#include <algorithm>

// Greedy algorithm doesn't always give the correct answer here;
// See dynamic programming code for this

int minNumCoins(int coins[], int numCoins, int amount)
{
	// Sort coins[]
	std::sort(coins, coins+numCoins, std::greater<int>());

	int res{0};

	for(int i = 0; i < numCoins; i++)
	{
		if(coins[i] <= amount && coins[i] != 0)
		{
			int reqCoins = std::floor(amount/coins[i]);
			res += reqCoins;
			amount -= reqCoins * coins[i];
		}

		if(amount <= 0)
			break;
	}

	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	int coins[4] = {1, 5, 2, 10};
	std::cout << "Min coins = " << minNumCoins(coins, 4, 57) << std::endl;

	return 0;
}

// g++ -std=c++11 CoinChange.cpp -o CoinChange