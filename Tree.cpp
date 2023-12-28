#include<iostream>
using namespace std;

class Node 
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
};

class Tree
{
private:
	Node *root;

	void insert(Node *&current, int value)
	{
		if (current == NULL)
			current = new Node(value);
		else
		{
			Node *temp = current;

			while (temp != NULL && temp->right)
				temp = temp->right;

			if (temp != NULL)
				temp->right = new Node(value);

			else
				current->left = new Node(value);
		}
	}

	void remove(Node *current, int value)
	{
		Node *prev = NULL;

		while (current != NULL)
		{
			if (current->data == value)
			{
				if (prev != NULL)
				{
					prev->right = current->right;
					delete current;
				}
				else
				{
					root = current->right;
					delete current;
				}
				return;

			}
			prev = current;
			current = current->right;
		}
		cout << "not found";
	}

public:
	Tree()
	{
		root = NULL;
	}

	void Insert(int root,int value)
	{
		insert(root, value);
	}

	void Remove(int value)
	{
		remove(root, value);
	}
	
};

