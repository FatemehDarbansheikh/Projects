#include<iostream>
using namespace std;

class Queue
{
private:
	int front, rear, size;
	int *queue;

public:
	Queue(int n)
	{
		size = n;
		queue = new int[size];
		front, rear = -1;
	}

	bool isEmpty()
	{
		if (front == rear)
			return true;
		else
			return false;
	}

	int Dequeue()
	{
		if (isEmpty() == true)
			return;
		return queue[++front];

	}

	void ReverseQueue()
	{
		int temp;
		int count = 0;

		for (int i = 0; i <(size / 2); i++)
		{
			temp = queue[i];
			queue[i] = queue[size - (i + 1)];
			queue[size - (i + 1)] = temp;
		}
		for (int i = 0; i < size; i++)
			cout << queue[i];
	}
};