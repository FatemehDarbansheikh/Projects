#include<iostream>
using namespace std;

void Merge(int array[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int *lefta = new int[n1];
	int *righta = new int[n2];

	for (int i = 0; i < n1; i++)
		lefta[i] = array[left + i];
	
	for (int j = 0;  j < n2; j++)
		righta[j] = array[mid + 1 + j];

	int i = 0, j = 0, k = left;

	while (i < n1&&j < n2)
	{
		if (lefta[i] <= righta[j])
		{
			array[k] = lefta[i];
			i++;
		}
		else
		{
			array[k] = righta[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = lefta[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = righta[j];
		j++;
		k++;
	}

	delete[] lefta;
	delete[] righta;

}
void MergeSort(int array[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(array, left, mid);
		MergeSort(array, mid + 1, right);

		Merge(array, left, mid, right);
	}

}