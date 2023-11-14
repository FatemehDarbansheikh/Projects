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


};