// Dynamic Programming >> p.223 ¹Ù´Ú °ø»ç

#include <iostream>

using namespace std;

constexpr int divider = 796796;

int Solve(int x)
{
	int dpTable[1001] = {};
	dpTable[1] = 1;
	dpTable[2] = 3;

	for (int i = 3; i <= x; ++i)
	{
		dpTable[i] = dpTable[i - 2] * 2 + dpTable[i - 1];
	}

	return dpTable[x] % divider;
}

int main()
{
	int n;
	cin >> n;

	int ans = Solve(n);

	cout << ans;

	return 0;
}
