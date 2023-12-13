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

class LinkedList
{
private:
	Node* head;
public:
	LinkedList()
	{
		head = NULL;
	}

	void InsertAtIndex(int data, int index)
	{
		Node *n = new Node(data);
	

		if (index == 0)
		{
			n->next = head;
			head = n;
		}
		else
		{
			Node *current = head;
			for (int i = 0;i< index - 1 && current; ++i)
				current = current->next;

			if (current != NULL)
			{
				n->next = current->next;
				current->next = n;
			}
			else
				return;
		}
		
	}

	void InsertAtEnd(int data)
	{
		Node *n = new Node(data);

		if (head == NULL)
			head = n;
		
		else
		{
			Node *current = head;

			while (current->next != NULL)
				current = current->next;

			current->next = n;
		}
	}

	void InsertAtBegin(int data)
	{
		Node *n = new Node(data);
		if (head == NULL)
		{
			head = n;
			head->next = NULL;

		}
		else
		{
			n->next = head;
			head = n;
		}
	}

	void UpdateNode(int data, int index)
	{
		if (head == NULL)
			return;

		Node *current = head;
		for (int i = 0; i < index&&current; ++i)
			current = current->next;
		if (current != NULL)
			current->data = data;
		else
			return;
	}

	int RemoveAtIndex(int index)
	{
		if (head == NULL)
			return;

		if (index == 0)
		{
			Node *temp = head;
			int removeData = temp->data;
			head = head->next;
			delete temp;
			return removeData;
		}
		else
		{
			Node *current = head;
			Node *prev = NULL;
			for (int i = 0; i < index && current; ++i)
			{
				prev = current;
				current = current->next;
			}
			if (current != NULL)
			{
				Node *temp = current;
				int removeData = temp->data;
				prev->next = current->next;
				delete temp;
				return removeData;
			}
			else
				return -1;
		}
	}

	int RemoveNodeAtEnd()
	{
		if (head == NULL)
			return;

		Node *current= head;
		Node *prev = NULL;
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
		}
		int removeData = current->data;
		if (prev != NULL)
		{
			prev->next = NULL;
			delete current;
		}
		else
		{
			delete head;
			head = NULL;
		}

		return removeData;
	}

	int RemoveNodeAtBegin()
	{
		if (head == NULL)
			return;

		Node *temp = head;
		int removeData = temp->data;
		head = head->next;
		delete temp;
		
		return removeData;
	}

	int SizeOfList()
	{
		int size = 0;
		if (head == NULL)
			return size;
		Node *temp = head;
		while (temp != NULL)
		{
			++size;
			temp = temp->next;
		}
		return size;
	}

	void Concatenate(LinkedList &otherList)
	{
		if (otherList.head == NULL)
			return;
		if (head == NULL)
			head = otherList.head;
		else
		{
			Node *current = head;
			while (current->next != NULL)
				current = current->next;
			current->next = otherList.head;
		}
	}

	void Invert()
	{
		if ((head == NULL) || (head->next == NULL))
			return;

		Node *prev = head;
		Node *current = prev->next;
		Node *nextN = current->next;

		prev->next = NULL;
		current->next = prev;

		while (nextN != NULL)
		{
			prev = current;
			current = nextN;
			nextN = nextN->next;
			current->next = prev;
		}
		head = current;
	}
};