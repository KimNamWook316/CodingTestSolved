#include <iostream>

using namespace std;

int table[45];

int fibo(int n)
{
	table[0] = 0;
	table[1] = 1;

	for (int i = 2; i <= n; ++i)
		table[i] = table[i - 1] + table[i - 2];

	return table[n];
}

int main()
{
	int n = 0;
	cin >> n;
	cout << fibo(n);

	return 0;
}