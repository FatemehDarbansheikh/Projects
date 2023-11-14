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

	

};