#include<iostream>
using namespace std;

void CountingSort(int array[], int n)
{
	int max = array[0];

	for (int i = 1; i < n; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	int *count = new int[max + 1];

	for (int i = 0; i <= max; i++)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[array[i]]++;

	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];

	int *result = new int[n];
	for (int i = n - 1; i >= 0; i--)
	{
		result[count[array[i]] - 1] = array[i];
		count[array[i]--];
	}

	for (int i = 1; i < n; i++)
		array[i] = result[i];

}