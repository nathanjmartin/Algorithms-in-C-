//selection sort algorithm


#include <iostream>
using namespace std;

int swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int array[], int n) {
	int minimum_index;

	for (int i = 0; i < n - 1; i++) {
		minimum_index = i;
		for (int j = i + 1; j < n; j++)
			if (array[j] < array[minimum_index])
				minimum_index = j;

		swap(&array[minimum_index], &array[i]);
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