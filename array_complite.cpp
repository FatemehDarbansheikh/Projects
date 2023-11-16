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
		array=new int[size];
	}

	void Insert(int object, int index)
	{
		if (index < size && index >= 0)
			array[index] = object;
		else
			return;
	}

	int Delete(int index)
	{
		int object=array[index];
		array[index] = 0;
		return object;
	}

	int Find(int object)
	{
		for (int i = 0; i < size; i++)
		{
			if (array[i] == object)
				return i;
			else
				return -1;
		}
	}

};