#include <iostream>
#include <deque>

int main(int argc, char const *argv[])
{
	int n{7}, k{3};
	int arr[7] = {10, 8, 5, 12, 15, 7, 6};

	std::deque<int> subArray;
	for(int i = 0; i < n; i++)
	{
		if(subArray.size() == k)
			subArray.pop_front();
		
		if(!subArray.empty())
		{
			while(!subArray.empty() && (arr[i] > arr[subArray.front()]))
				subArray.pop_front();
			
			subArray.push_back(i);
		}
		else
			subArray.push_front(i);
		
		// print subArry in each iteration
		// for(auto& x : subArray)
		// 	std::cout << arr[x] << ", ";
		// std::cout << std::endl;
		if(i >= k-1)
			std::cout << arr[subArray.front()] << std::endl;
	}
	return 0;
}

// g++ -std=c++11 MaximumOfAllSubArrays.cpp -o MaximumOfAllSubArrays