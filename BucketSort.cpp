#include<iostream>
using namespace std;

void insertionSort(float a[], int size)
{
	for (int i = 1; i < size; i++)
	{
		float key = a[i];
		int j = i - 1;

		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void BucketSort(float a[], int size)
{
	
	const int Bcount = 10;
	int *Bindex = new int[size];
	int *Bsize = new int[Bcount];
	float **buckets = new float *[Bcount];

	for (int i = 0; i < Bcount; i++)
		buckets[i] = new float[size];

	for (int i = 0; i < size; i++)
	{
		Bindex[i] = Bcount*a[i];
		buckets[Bindex[i]][Bsize[Bindex[i]]] = a[i];
		Bsize[Bindex[i]]++;
	}

	for (int i = 0; i < Bcount; i++)
		insertionSort(buckets[i], Bsize[i]);

	int index = 0;
	for (int i = 0; i < Bcount; i++)
		for (int j = 0; j < Bsize[i]; j++)
			a[index++] = buckets[i][j];

	delete[] Bindex;
	delete[] Bsize;
	for (int i = 0; i < Bcount; i++)
		delete[] buckets[i];

	delete[] buckets;

}