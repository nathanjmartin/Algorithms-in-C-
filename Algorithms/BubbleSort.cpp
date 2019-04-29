//Bubble sort implementation in C++
/*
Bubble sort is the simplest sorting algorithm that works by repeatedly
swapping the adjacent elements if they are in the wrong order

*/

//could just using a swapping algorithm built into <algorithm>, but important to understand
//time complexity as well as how they work

#include <iostream>

using namespace std;

//swap helper algorithm
void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//bubble sort algorithm
void bubbleSort(int array[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
}

//printing out the array
void printArray(int array[], int size) {
	for (int i = 0; i < size; i++)
		cout << array[i];
}


//main
int main() {
	int array[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(array) / sizeof(array[0]);
	bubbleSort(array, n);
	printArray(array, n);
	return 0;
}
