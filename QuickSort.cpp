#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Partition(int array[], int low, int high)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j <= high-1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array[i], array[j]);
		}
	}
	swap(array[i + 1], array[high]);
	return i + 1;
}

void QuickSort(int array[], int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(array, low, high);
		QuickSort(array, low, pivot - 1);
		QuickSort(array, pivot + 1, high);
	}
}