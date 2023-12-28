#include<iostream>
using namespace std;

void InsertionSort(int array[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++)
	{
		 key = array[i];
		 j = i - 1;
		 while (j >= 0 && array[j] > key)
		 {
			 array[j + 1] = array[j];
			 j = j - 1;
		 }
		 array[j + 1] = key;
	}
}