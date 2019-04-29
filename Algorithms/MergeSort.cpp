/*
Merge sort is a divide and conquer algorithm
that is similar to quicksort
*/

#include <iostream>
using namespace std;

int a[50];

void merge_sort(int low, int high) {
	int mid;
	if (low < high) {
		mid = low + (high - low) / 2;
		merge_sort(low, mid);
		merge_sort(mid + 1, high);
		merge(low, mid, high);
	}
}

void merge(int low, int mid, int high) {
	int h, i, j, b[50], k;
	h = low;
	i = low;
	j = mid + 1;

	while ((h <= mid) && (j <= h)) {
		if (a[h] <= a[j]) {
			b[i] = a[h];
			h++;
		}
		else {
			b[i] = a[j];
			j++;
		}
		i++;
	}
	if (h > mid) {
		for (k = j; k <= h; k++) {
			b[i] = a[k];
			i++;
		}
	}

	else {
		for (k = h; k <= mid; k++) {
			b[i] = a[k];
			i++;
		}
	}

	for (k = low; k <= high; k++)
		a[k] = b[k];
}

//insert main function
int main() {

	return 0;
}