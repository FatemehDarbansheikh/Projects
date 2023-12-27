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

class HashTable
{
private:
	int size;
	Node **table;

	int HashFunction(int key)
	{
		 
		return key % size;
	}

public:
	HashTable(int size)
	{
		this->size = size;
		table = new Node*[size];
		for (int i = 0; i < size; i++)
			table[i] =NULL;
	}

	void Insert(int key,int value)
	{
		int index = HashFunction(key);
		Node *n = new Node(value);
		n->next = table[index];
		table[index] = n;
	}

	int Search(int key)
	{
		int index = HashFunction(key);
		Node *current = table[index];
		while (current != NULL)
		{
			if (current->data == key)
				return current->data;
			current = current->next;
		}
		return -1;
	}

	int Remove(int key)
	{
		int index = HashFunction(key);
		Node *current = table[index];
		Node *prev = NULL;

		while (current != NULL && current->data != key)
		{
			prev = current;
			current = current->next;
		}
		if (current != NULL)
		{
			if (prev != NULL)
				prev->next = current->next;
			else
				table[index] = current->next;

			int value = current->data;
			delete current;
			return value;
		}
	}

};