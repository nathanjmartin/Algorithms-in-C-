/*

Insertion sort is a simple sorting algoirhtm that works
the way we sort playing cards in our hands

*/

#include <math.h>
#include <iostream>

using namespace std;

//utility function
void printArray(int array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i];
	}
}

//insertion sort
void insertionSort(int array[], int n) {
	int key, j;
	for (int i = 1; i < n; i++) {
		key = array[i];
		j = i - 1;

		/* Move elements of array[0..i-1],
		that are greater than the key, to one position
		ahead of their current position
		*/

		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}

		array[j + 1] = key;
	}
}

int main() {
	int array[] = { 20, 15, 14, 2, 9 };
	int n = sizeof(array) / sizeof(array[0]);

	insertionSort(array, n);
	printArray(array, n);

	return 0;
}

