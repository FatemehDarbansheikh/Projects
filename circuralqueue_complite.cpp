#include <iostream>
#include <string>
using namespace std;


class circuralqueue_amd
{
private:
    int front, rear, size;
    int *queue;

public:
    circuralqueue_amd(int n, int m)
    {
        size = n;
        queue = new int[size];
        front, rear = 0;
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
        else
        {
            int object = front;
            front = (front + 1) % size;
            return queue[object];
        }
    }

    int *ReverseQueue()
    {
        int temp[];
        int conter = -1;
        int k = 0;
        while (k <= size && isEmpty() == false)
        {
            temp[conter++] = Dequeue();
        }

        for (int i = conter; i >= 0; i--)
        {
            queue[rear] = temp[i];
            rear = (rear + 1) % size;
        }
        return queue;
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
}
;
