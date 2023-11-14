class CircularQueue
{
private:
	int front, rear, size;
	int *queue;

public:
	CircularQueue(int n)
	{
		size = n;
		queue = new int[size];
		front, rear = -1;

	}


};