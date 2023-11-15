#include<iostream>
using namespace std;

class Array
{
private:
	int *array;
	int size;

public:
	Array(int n)
	{
		size = n;
		array = new int[size];
	}

	void Insert(int object, int index)
	{
		if (index < size && index >= 0)
			array[index] = object;
		else
			return;
	}

	int Find(int object)
	{
		for (int i = 0; i < size; i++)
		{
			if (array[i] == object)
				return i;		
		}
		return -1;
	}



};