//c++ implementation of the binary search cpp
#include <iostream>
using namespace std;


//recursive binarysearch
int binarySearch(int array[], int low, int high, int key) {
	int mid;

	while (high >= low) {
		mid = low + (high - 1) / 2;

		//if the element is present in the middle itself, return mid
		if (array[mid] == x)
			return mid;

		//if element is smaller than mid, then it can only be in the bottom half of the
		//array (low side)
		if (array[mid] > x)
			return binarySearch(array, low, mid - 1, key);
		
		//else the element can only be in the right side of the array (high)
		return binarySearch(array, mid + 1, high, key);
	}
	//if element is not in the array
	return -1;
}


//main
int main() {
	int array[] = { 1, 2, 3, 4, 5, 6 };
	int key = 5;
	int n = sizeof(array) / sizeof(array[0]);
	int result = binarySearch(arr, 0, n - 1, key);

	if (result == -1)
		cout << "Element not present in the array";

	else
		cout << "Element present at index" << result;

}