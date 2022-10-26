// �׸��� �˰��� >> p.92 ū ���� ��Ģ

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> nums(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	// ù �ۼ� ���
 //	{
 //		int answer = 0;
 //		int max = -1, max2 = -1;
 //
 //		for (int i = 0; i < n; ++i)
 //		{
 //			if (max <= nums[i])
 //			{
 //				max2 = max;
 //				max = nums[i];
 //			}
 //		}
 //
 //		int cnt = 0;
 //		while (m > 0)
 //		{
 //			if (cnt == 3)
 //			{
 //				answer += max2;
 //				cnt = 0;
 //			}
 //			else
 //			{
 //				answer += max;
 //				++cnt;
 //			}
 //			--m;
 //		}
 //
 //		cout << answer;
 //	}
 //
	// ������ ����
	{
		int answer = 0;
		int max = -1, max2 = -1;

		sort(nums.begin(), nums.end(), greater<int>());

		// ���� ū ���� �ι�°�� ū ��
		max = nums[0];
		max2 = nums[1];

		// ���� ū �� ���� Ƚ��
		int maxCount = (m / (k + 1)) * k + (m % (k + 1));

		answer += maxCount * max;
		answer += (m - maxCount) * max2;

		cout << answer;
	}
	
	return 0;
}