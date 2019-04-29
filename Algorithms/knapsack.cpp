//knapsack implementation c++

#include <iostream>
using namespace std;

//max utility funvtion that returns the max of two values
int max(int a, int b) {
	return (a > b) ? a : b;
}


//recursive knapsack algorithm
int KnapSack(int w, int wt[], int val[], int n) {
	if (n == 0 || w == 0)
		return 0;

	//if the weight of the nth item is more than the knapsack capacity (w), then
	//the nth item cannot be included in the optimal solution
	if (wt[n - 1] > w) {
		return KnapSack(w, wt, val, n - 1);

		//Return the maximum of two cases
		// (1) nth item included
		// (2) nth item not included
	}

	else {
		return max(val[n - 1] + KnapSack(w - wt[n - 1], wt, val, n - 1), KnapSack(w, wt, val, n - 1));
	}
}

int main() {
	int val[] = { 20, 60, 180 };
	int wt[] = { 10, 20, 30 };
	int w = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << KnapSack(w, wt, val, n);
	return 0;
}