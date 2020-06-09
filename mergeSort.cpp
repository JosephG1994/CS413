// Merge sort algorithm to sort a list of n number in decreasing order. 
#include<iostream>
using namespace std;

// Merge two subarrays of array[]
void merge(int array[], int left, int right)
{
	if(left < right)
	{
		int mid = (left + right) / 2;

		// Sort the 1st and 2nd halves
		merge(array, left, mid);
		merge(array, mid + 1, right);

		int i, j, k;
		i = left;
		j = mid + 1;
		k = left;

		// create temp array
		int tempArr[100];

		while(i <= mid && j <= right)
		{
			if(array[i] > array[j])
				tempArr[k++] = array[i++];
			else
				tempArr[k++] = array[j++];
		}
		while(i <= mid)
			tempArr[k++] = array[i++];
		while(j <= right)
			tempArr[k++] = array[j++];
		for(i = left; i <= right; i++)
			array[i] = tempArr[i];
	}
}

int main()
{
	int i, size;
	cout <<"Enter size of list: ";
	cin >> size;

	int a[size];
	cout <<"Enter list: ";
	for(i = 0; i < size; i++)
		cin >> a[i];

	merge(a, 0, size - 1);
	cout <<"Sorted list: ";
	for(i = 0; i < size; i++)
		cout << a[i] <<" ";
}
