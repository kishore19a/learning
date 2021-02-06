#include <iostream>

void merge(int arr[], int lb, int mid, int ub)
{
	int n{(mid - lb + 1)}, m{(ub - mid)};
	int left[n], right[m];

	for(int i = 0; i < n; i++) { left[i] = arr[lb + i]; }
	for(int i = 0; i < m; i++) { right[i] = arr[mid + 1 + i]; }

	int i{0}, j{0}, k{lb};
	
	while((i < n) && (j < m))
	{
		if(left[i] < right[j]) { arr[k] = left[i]; k++; i++; }
		else { arr[k] = right[j]; k++; j++; }
	}

	while(i < n) { arr[k] = left[i]; k++; i++; }
	while(j < m) { arr[k] = right[j]; k++; j++; }
}

void mergeSort(int arr[], int lb, int ub)
{
	if(ub > lb)
	{
		int mid = lb + (ub - lb) / 2;
		mergeSort(arr, lb, mid);
		mergeSort(arr, mid+1, ub);
		merge(arr, lb, mid, ub);
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int arr[5] = {10, 5, 30, 15, 7};

	for(int i = 0; i < 5; i++)
		std::cout << arr[i] << ", ";
	std::cout << std::endl;

	mergeSort(arr, 0, 4);
	for(int i = 0; i < 5; i++)
		std::cout << arr[i] << ", ";
	std::cout << std::endl;

	return 0;
}

// g++ -std=c++11 MergeSort.cpp -o MergeSort