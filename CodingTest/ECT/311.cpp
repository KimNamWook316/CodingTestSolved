// 유형별 기출문제 : 그리디 알고리즘 >> p.311
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adv;

int getMaxGroup(int n)
{
	int idx = 0;
	int need = 0;
	int groupCount = 0;

	while(idx < adv.size())
	{
		need = adv[idx];

		if (adv.size() - need < idx)
			break;
		else
		{
			++groupCount;
			idx += (need + 1);
		}
	}

	return groupCount;
}

int main()
{
	int n;
	cin >> n;

	adv.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> adv[i];

	sort(adv.begin(), adv.end());

	cout << getMaxGroup(n);

	return 0;
}
