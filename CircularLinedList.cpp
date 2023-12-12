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
		next = nullptr;
	}
};

class CircularLinkedList
{
private:
	Node* head;
public:
	CircularLinkedList()
	{
		head = NULL;
	}

	void InsertAtIndex(int data, int index)
	{
		Node *n = new Node(data);
		

		if (head == NULL && index != 0)
			return;

		if (index == 0)
		{
			n->next = head;
			Node *temp = head;
			while (temp->next != head)
				temp = temp->next;
			temp->next = n;
			head = n;
		}
		
		else
		{
			Node *temp = head;
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->next;
				if (temp == head)
					return;
			}
			n->next = temp->next;
			temp->next = n;
		}
	}

	void InsertAtEnd(int data)
	{
		Node *n = new Node(data);

		if (head==NULL)
		{
			head = n;
			head->next = head;

		}
		else
		{
			Node *temp = head;

			while (temp->next != head)
				temp = temp->next;
			temp->next = n;
			n->next = head;
		}
	}
		
	void InsertAtBegin(int data)
	{
		Node *n = new Node(data);
		if (head == NULL)
		{
			head = n;
			head->next = head;

		}
		else
		{
			Node *temp = head;
			while (temp->next != head)
				temp = temp->next;
		
			n->next = head;
			temp->next = n;
			head = n;
		}
	}

	void UpdateNode(int data, int index)
	{
		if (head == NULL)
			return;

		Node *temp = head;
		int c = 0;
		do
		{
			if (c == index)
			{
				temp->data = data;
				break;
			}
			temp = temp->next;
			++c;
		} while (temp != head);

		return;
	}

	int RemoveAtIndex(int index)
	{
		if (head == NULL)
			return;

		Node *temp = head;
		Node *prev = NULL;
		int c = 0;
		do
		{
			if (c == index)
			{
				if (prev != NULL)
				{
					prev->next = temp->next;
					int returnData = temp->data;
					delete temp;
					return returnData;
				}

				else
				{
					Node *last = head;
					while (last->next != head)
						last = last->next;
					int returnData = head->data;
					if (head->next == head)
					{
						delete head;
						head = NULL;
					}
					else
					{
						last->next = head->next;
						delete head;
						head = last->next;
					}
					return returnData;
				}
			}
			prev = temp;
			temp = temp->next;
			++c;
		} while (temp != head);

		return;
	}
	
	int RemoveNodeAtEnd()
	{
		if (head == NULL)
			return;

		Node *temp = head;
		Node *prev = NULL;
		while (temp->next != head)
		{
			prev = temp;
			temp = temp->next;
		}
		int returnData = temp->data;
		if (prev != NULL)
		{
			prev->next = head;
			delete temp;
		}
		else
		{
			delete head;
			head = NULL;
		}

		return returnData;

	}
	
	int RemoveNodeAtBegin()
	{
		if (head == NULL)
			return;

		Node *temp = head;
		int returnData = temp->data;
		
		if (head->next == head)
		{
			delete head;
			head = NULL;
		}
		else
		{
			Node *last = head;
			while (last->next != head)
				last = last->next;

			last->next = head->next;
			head = head->next;
			delete temp;
		}
		
		return returnData;
	}
	
	int SizeOfList()
	{
		int size;
		if (head == NULL)
			return size;
		Node *temp = head;
		do {
			size++;
			temp = temp->next;
		} while (temp != head);

		return size;	
	}

	void Concatenate(CircularLinkedList &otherList)
	{
		if (otherList.head == NULL)
			return;

		if (head == NULL)
			head = otherList.head;
		else
		{
			Node *temp = head;
			while (temp->next != head)
				temp = temp->next;
			temp->next = otherList.head;
			Node *otherTemp = otherList.head;
			while (otherTemp->next != otherList.head)
				otherTemp = otherTemp->next;
			otherTemp->next = head;
		}

	}
	
	void Invert()
	{
		if ((head == NULL) || (head->next == head))
			return;

		Node *prev;
		Node *current = head;
		Node *nextN = NULL;

		do {
			prev = current->next;
			current->next = nextN;
			nextN = current;
			current = prev;
		} while (current != head);
		head->next = nextN;
		head = nextN;

	}

	


};