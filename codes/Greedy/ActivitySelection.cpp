#include <iostream>
#include <vector>
#include <algorithm>

// Maximum number of activity that can be selected -> sort by increasing order of finish time

void selectActivities(std::vector<std::pair<int, int>>& activityList)
{
	// sort by finishing time
	std::sort(activityList.begin(), activityList.end(), [](std::pair<int, int> a, std::pair<int, int> b){
		return(a.second < b.second);
	});

	int prev{0};
	std::cout << "(" << activityList[prev].first << ", " << activityList[prev].second << ")" << std::endl;

	for(int i = 1; i < activityList.size(); i++)
	{
		if(activityList[prev].second <= activityList[i].first)
		{
			prev = i;
			std::cout << "(" << activityList[prev].first << ", " << activityList[prev].second << ")" << std::endl;
		}
	}

	std::cout << std::endl;

}

void printActivity(std::vector<std::pair<int, int>>& activityList)
{
	for(auto& activity : activityList)
		std::cout << "(" << activity.first << ", " << activity.second << ")" << std::endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	std::vector<std::pair<int, int>> activityList = {{1, 3}, {10, 11}, {3, 8}, {2, 4}, {5, 6}, {12, 14}, {3, 6}};
	printActivity(activityList);
	std::cout << std::endl;

	selectActivities(activityList);
	printActivity(activityList);
	std::cout << std::endl;

	return 0;
}

// g++ -std=c++11 ActivitySelection.cpp -o ActivitySelection