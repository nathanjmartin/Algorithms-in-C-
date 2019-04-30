/*
Fn = Fn-1 + Fn-2

Going to have both recursive, dynamic programming, and divide and conquer
examples.

*/


#include <iostream>
using namespace std;

//recursive example
int fibRecursive(int n) {
	//base case needed for recursion
	if (n <= 1)
		return n;

	return fibRecursive(n - 1) + fibRecursive(n - 2);

}


//dynamic programming example
int fibDynamicOne(int n) {
	int f[n + 1];

	f[0] = 0;
	f[1] = 1;

	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}

	return f[n];
}

//divide and conquer example
int fibDivideAndConquer(int n)
{
	int F[2][2] = { {1,1},{1,0} };
	if (n == 0)
		return 0;
	power(F, n - 1);

	return F[0][0];
}

void multiply(int F[2][2], int M[2][2])
{
	int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void power(int F[2][2], int n)
{
	int M[2][2] = { {1,1},{1,0} };

	// n - 1 times multiply the matrix to {{1,0},{0,1}} 
	for (int i = 2; i <= n; i++)
		multiply(F, M);
}
