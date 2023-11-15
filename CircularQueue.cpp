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
		front, rear = 0;

	}

	bool isFull()
	{
		if (front == (rear + 1) % size)
			return true;
		else
			return false;
	}

	void Enqueue(int object)
	{
		if (isFull() == true)
			return;
		rear = (rear + 1) % size;
		queue[rear] = object;
	}

	int Peek()
	{
		if (isEmpty() == true)
			return;
		else
			return queue[front];
	}
};