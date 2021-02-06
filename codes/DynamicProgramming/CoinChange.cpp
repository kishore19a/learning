#include <iostream>

int getCount(int coins[], int n, int sum)
{
	if(sum == 0) return 1;
	if(n == 0) return 0;
	int res = getCount(coins, n-1, sum);
	if(coins[n-1] <= sum)
		res += getCount(coins, n, sum-coins[n-1]);
}

int main(int argc, char const *argv[])
{
	int coins[4] = {2, 5, 3, 6};
	std::cout << getCount(coins, 4, 10) << std::endl;
	return 0;
}

// g++ -std=c++11 CoinChange.cpp -o CoinChange