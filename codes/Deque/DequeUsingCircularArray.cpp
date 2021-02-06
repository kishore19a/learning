#include <iostream>

class DequeUsingCircularArray
{
public:
	DequeUsingCircularArray(int cap) : cap(cap)
	{
		arr = new int[cap];
	}

	bool isEmpty();
	bool isFull();

	void insertFront(int x);
	void insertRear(int x);

	void deleteFront();
	void deleteRear();

private:
	int cap, size{0}, front{0};
	int *arr;
};

bool DequeUsingCircularArray::isEmpty()
{
	return (size == 0);
}

bool DequeUsingCircularArray::isFull()
{
	return (size == cap);
}

void DequeUsingCircularArray::insertFront(int x)
{
	if(isFull()) return;
	else
	{
		front = (front - 1 + cap) % cap;
		arr[front] = x;
		size++; 
	}
}

void DequeUsingCircularArray::insertRear(int x)
{
	if(isFull()) return;
	else
	{
		int rear = (front + size) % cap; // rear = rear + 1 is also combined here
		arr[rear] = x;
		size++;
	}
}

void DequeUsingCircularArray::deleteFront()
{
	if(isEmpty) return;
	else
	{
		front = (front + 1) % cap;
		size--;
	}
}

void DequeUsingCircularArray::deleteRear()
{
	if(isEmpty) return;
	else size--;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}