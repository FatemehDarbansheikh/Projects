#include <iostream>
using namespace std;

class MinHeap 
{
private:
	static const int maxSize = 100;
	int heapArray[maxSize];
	int size;

	void heapifyUp(int index) 
	{
		while (index > 0) 
		{
			int parentIndex = (index - 1) / 2;
			if (heapArray[index] < heapArray[parentIndex]) 
			{
				int temp = heapArray[index];
				heapArray[index] = heapArray[parentIndex];
				heapArray[parentIndex] = temp;

				index = parentIndex;
			}
			else
				break;
		}
	}

	void heapifyDown(int index) 
	{
		int leftChild = 2 * index + 1;
		int rightChild = 2 * index + 2;
		int smallest = index;

		if (leftChild < size && heapArray[leftChild] < heapArray[smallest])
			smallest = leftChild;
		
		

		if (rightChild < size && heapArray[rightChild] < heapArray[smallest])
			smallest = rightChild;
			
		

		if (smallest != index) 
		{
			int temp = heapArray[index];
			heapArray[index] = heapArray[smallest];
			heapArray[smallest] = temp;

			heapifyDown(smallest);
		}
	}

public:
	MinHeap()
	{
		size = 0;
	}

	void insert(int value) 
	{
		if (size < maxSize) 
		{
			heapArray[size] = value;
			heapifyUp(size);
			size++;
		}
		else 
			cout << "Heap is full.\n";
	}

	int remove() 
	{
		if (size > 0) 
		{
			int minValue = heapArray[0];
			heapArray[0] = heapArray[size - 1];
			size--;
			heapifyDown(0);
			return minValue;
		}
		else 
		{
			cout << "Heap is empty.\n";
			return -1; 
		}
	}

	void heapify() 
	{
		for (int i = size / 2 - 1; i >= 0; i--)
			heapifyDown(i);
	}

	void decreaseKey(int index, int newValue) 
	{
		if (index < size && newValue < heapArray[index]) 
		{
			heapArray[index] = newValue;
			heapifyUp(index);
		}
	}

	void printHeap() const 
	{
		cout << "MinHeap: ";
		for (int i = 0; i < size; i++)
			cout << heapArray[i] << " ";
			
		cout << "\n";
	}
};



class MaxHeap 
{
private:
	static const int maxSize = 100;
	int heapArray[maxSize];
	int size;

	void heapifyUp(int index) 
	{
		while (index > 0) 
		{
			int parentIndex = (index - 1) / 2;
			if (heapArray[index] > heapArray[parentIndex]) 
			{
				int temp = heapArray[index];
				heapArray[index] = heapArray[parentIndex];
				heapArray[parentIndex] = temp;

				index = parentIndex;
			}
			else
				break;
		}
	}

	void heapifyDown(int index) 
	{
		int leftChild = 2 * index + 1;
		int rightChild = 2 * index + 2;
		int largest = index;

		if (leftChild < size && heapArray[leftChild] > heapArray[largest])
			largest = leftChild;
			
		if (rightChild < size && heapArray[rightChild] > heapArray[largest])
			largest = rightChild;
			
		if (largest != index) 
		{
			int temp = heapArray[index];
			heapArray[index] = heapArray[largest];
			heapArray[largest] = temp;

			heapifyDown(largest);
		}
	}

public:
	MaxHeap()
	{
		size = 0;
	}

	void insert(int value) 
	{
		if (size < maxSize) 
		{
			heapArray[size] = value;
			heapifyUp(size);
			size++;
		}
		else 
			cout << "Heap is full.\n";
		
	}

	int remove() 
	{
		if (size > 0) 
		{
			int maxValue = heapArray[0];
			heapArray[0] = heapArray[size - 1];
			size--;
			heapifyDown(0);
			return maxValue;
		}
		else 
		{
			cout << "Heap is empty.\n";
			return -1;
		}
	}

	void heapify() 
	{
		for (int i = size / 2 - 1; i >= 0; i--)
			heapifyDown(i);
	}

	void decreaseKey(int index, int newValue) 
	{
		if (index < size && newValue > heapArray[index]) 
		{
			heapArray[index] = newValue;
			heapifyUp(index);
		}
	}

	void printHeap() 
	{
		cout << "MaxHeap: ";
		for (int i = 0; i < size; i++)
			cout << heapArray[i] << " ";
		
		cout << "\n";
	}
};
