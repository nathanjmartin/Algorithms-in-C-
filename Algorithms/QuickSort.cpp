//quick sort divide and conquer algorithm

#include <iostream>

using namespace std;

//utility function
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */

int partition(int array[], int low, int high) {
	int pivot = array[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (array[j] <= pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i];
	}
}


int main() {



	return 0;
}