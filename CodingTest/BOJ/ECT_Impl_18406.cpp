#include <iostream>

using namespace std;

bool solve(int n)
{
	int num = n;
	int count = 0;
	while (num != 0)
	{
		num /= 10;
		++count;
	}

	int lSum = 0;
	int rSum = 0;
	for (int i = 0; i < count / 2; ++i)
	{
		rSum += (n % 10);
		n /= 10;
	}

	for (int i = 0; i < count / 2; ++i)
	{
		lSum += (n % 10);
		n /= 10;
	}

	return lSum == rSum;
}

int main()
{
	int n;
	cin >> n;

	if (solve(n))
		cout << "LUCKY";
	else
		cout << "READY";

	return 0;
}
