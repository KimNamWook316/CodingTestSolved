// Dynamic Programming >> p.220 개미 전사

#include <iostream>

using namespace std;

int n;
int arr[101] = {};

int MySolve(int x)
{
	int dpTable[101] = {};
	int ans = 0;

	for (int i = 1; i <= x; ++i)
	{
		if (dpTable[i - 1] > dpTable[i - 2])
			dpTable[i] = dpTable[i - 1];
		else
			dpTable[i] = dpTable[i - 1] + arr[i - 1];
	}

	return dpTable[x];
}

int Solve(int x)
{
	int dpTable[101] = {};
	int ans = 0;

	dpTable[0] = arr[0];
	dpTable[1] = max(arr[0], arr[1]);

	// 점화식 -> An = max(A(n-2) + k, A(n-1))
	for (int i = 2; i <= x; ++i)
	{
		dpTable[i] = max(dpTable[i - 2] + arr[i], dpTable[i - 1]);
	}

	return dpTable[x];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) { cin >> arr[i]; }

	cout << MySolve(n) << endl;
	cout << Solve(n) << endl;

	return 0;
}