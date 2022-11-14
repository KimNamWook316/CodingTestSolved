// 유형별 기출문제 : 그리디 알고리즘 >> p.314
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int cantMake(vector<int>& coins)
{
	sort(coins.begin(), coins.end());

	int target = 1;
	for (int i = 0; i < n; ++i)
	{
		if (coins[i] > target)
			return target;

		target += coins[i];
	}
}

int main()
{
	cin >> n;
	vector<int> coins(n);
	for (int i = 0; i < n; ++i) { cin >> coins[i]; }

	cout << cantMake(coins);

	return 0;
}
