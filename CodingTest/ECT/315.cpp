// 유형별 기출문제 : 그리디 알고리즘 >> p.315
#include <iostream>

using namespace std;

int n, m;
int arr[1000];

int solve()
{
	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[i] == arr[j])
				continue;

			++answer;
		}
	}

	return answer;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) { cin >> arr[i]; }

	cout << solve();

	return 0;
}
