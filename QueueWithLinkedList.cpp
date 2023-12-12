#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int value)
	{
		data = value;
		next = NULL;
	}
};

class Queue
{
private:
	Node *front;
	Node *rear;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
	}

	bool isEmpty()
	{
		if (front == NULL)
			return true;
		else
			return false;
	}

	void Enqueue(int object)
	{
		Node *n = new Node(object);

		if (isEmpty()==true)
			front = rear = n;
		else
		{
			rear->next = n;
			rear = n;
		}
			
	}

	int Dequeue()
	{
		if (isEmpty() == true)
			return;

		Node *temp = front;
		int object = temp->data;
		front = front->next;
		delete temp;
		return object;
	}

	int Peek()
	{
		if (isEmpty() == true)
			return;

		return front->data;
	}

	void ReverseQueue()
	{
		Node *prev;
		Node *current;
		Node *nextN;
		
		if (isEmpty()==true)
			return;
		if (front->next == NULL)
			return;

		prev = front;
		current = prev->next;
		nextN = current->next;
		prev->next = NULL;
		current->next = prev;

		while (nextN != NULL)
		{
			prev = current;
			current = nextN;
			nextN = nextN->next;
			current->next = prev;
		}

		front = current;

	}

};
