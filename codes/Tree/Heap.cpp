#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

class MinHeap
{
public:
	MinHeap(int c)
	{
		arr = new int[c];
		capacity = c;
	}

	void insert(int elem);

	void printHeap();

	int left(int i) { return (2*i + 1); }
	int right(int i) { return (2*i + 2); }
	int parent(int i) { return std::floor((i-1)/2); }

private:
	int* arr;
	int size{0}, capacity{0};

	void heapify(int elementToHeapify);
};

void MinHeap::printHeap()
{
	for(int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void MinHeap::heapify(int elementToHeapify)
{
	if(elementToHeapify == 0) 
	{
		if((left(elementToHeapify) < size) && (right(elementToHeapify) < size))
			if(arr[elementToHeapify] < arr[left(elementToHeapify)]) && (arr[elementToHeapify] < arr[right(elementToHeapify)])
				return;
	}
	else
	{
		if(arr[parent(elementToHeapify)] > arr[elementToHeapify])
		{
			// move lower element up
			int x = arr[parent(elementToHeapify)];
			arr[parent(elementToHeapify)] = arr[elementToHeapify];
			arr[elementToHeapify] = x;

			elementToHeapify = parent(elementToHeapify);
			heapify(elementToHeapify);
		}
		else if((arr[left(elementToHeapify)] < arr[elementToHeapify]) || (arr[right(elementToHeapify)] < arr[elementToHeapify]))
		{
			// move bigger element down
			int elementToSwap;
			if(arr[left(elementToHeapify)] < arr[right(elementToHeapify)])
				elementToSwap = left(elementToHeapify);
			else 
				elementToSwap = right(elementToHeapify);

			int x = arr[elementToHeapify];
			arr[elementToHeapify] = arr[elementToSwap];
			arr[elementToSwap] = x;

			elementToHeapify = elementToSwap;
			heapify(elementToHeapify);
		}
	}
}

void MinHeap::insert(int elem)
{
	if(size < capacity)
	{
		size++;
		arr[size-1] = elem;
		heapify(size-1);
	}
	else
	{
		std::cout << "Max capacity of heap reached" << std::endl;
		return;
	}
}

int main(int argc, char const *argv[])
{
	MinHeap minHeap(10);

	minHeap.insert(40);
	minHeap.insert(30);
	minHeap.insert(50);
	minHeap.insert(20);

	minHeap.printHeap();

	return 0;
}

// g++ -std=c++11 Heap.cpp -o Heap