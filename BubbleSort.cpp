#include<iostream>
using namespace std;

void BubbleSort(int array[], int n)
{
	bool flag;
	for (int i = 0; i < n - 1; i++)
	{
		flag = false;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				flag = true;
			}
		}

		if (flag == false)
			break;
	}
}