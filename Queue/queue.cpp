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

	
};