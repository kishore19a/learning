#include <iostream>

class DequeUsingArray
{
public:
	DequeUsingArray(int cap) : cap(cap)
	{
		arr = new int[cap];
	}

	bool isEmpty();
	bool isFull();
	void insertRear(int x);
	void deleteRear();
	void insertFront(int x);
	void deleteFront();
	int getFront();
	int getRear();
	void printDeque();

private:
	int size{0}, cap{0};
	int *arr;
};

bool DequeUsingArray::isEmpty()
{
	return (size == 0);
}

bool DequeUsingArray::isFull()
{
	return (size == cap);
}

void DequeUsingArray::insertRear(int x)
{
	if(isFull()) return;
	else
	{
		arr[size] = x;
		size++;
	}
}

void DequeUsingArray::deleteRear()
{
	if(isEmpty()) return;
	else size--;
}

void DequeUsingArray::insertFront(int x)
{
	if(isFull()) return;
	else
	{
		for (int i = size-1; i >= 0; i--)
			arr[i+1] = arr[i];

		arr[0] = x;
		size++;
	}
}

void DequeUsingArray::deleteFront()
{
	if(isEmpty()) return;
	else
	{
		for (int i = 0; i < size; i++)
			arr[i] = arr[i+1];

		size--;
	}
}

int DequeUsingArray::getRear()
{
	if(isEmpty()) return -1;
	else return arr[size-1];
}

int DequeUsingArray::getFront()
{
	if(isEmpty()) return -1;
	else return arr[0];
}

void DequeUsingArray::printDeque()
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	DequeUsingArray dequeUsingArray(5);

	dequeUsingArray.insertFront(1);
	dequeUsingArray.insertRear(2);
	dequeUsingArray.insertRear(3);
	dequeUsingArray.insertFront(0);
	dequeUsingArray.insertFront(-1);
	dequeUsingArray.printDeque();

	dequeUsingArray.deleteFront();
	dequeUsingArray.deleteRear();
	dequeUsingArray.printDeque();

	return 0;
}

// g++ -std=c++11 DequeUsingArray.cpp -o DequeUsingArray