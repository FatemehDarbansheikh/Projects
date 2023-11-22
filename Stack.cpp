#include<iostream>
using namespace std;

class stackStr
{
private:
	int *stack;
	int top;
	int size;

public:
	stackStr(int n)
	{
		size = n;
		top = -1;
		stack = new int[size];
	}

	bool isEmpty()
	{
		if (top < 0)
			return true;
		else
			return false;
	}


	int Peek()
	{
		if (isEmpty() == true)
			return -1;
		return stack[top];
	}

};

