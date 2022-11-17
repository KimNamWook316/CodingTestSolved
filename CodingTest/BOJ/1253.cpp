#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> nums;
int n;

int solution()
{
	int ans = 0;

	// 0�� �����ϴ°� : ����ȭ
	bool zero = false;
	
	// ����, <����Ƚ��, ��� ���� ����>
	map<int, pair<int, bool>> numSet;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 0)
			zero = true;

		++numSet[nums[i]].first;
		numSet[nums[i]].second = false;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int sum = nums[i] + nums[j];

			// ���ؼ� 0�� ������ ��쿡 ���� ó��
			if (zero && sum == 0)
			{
				// 0�� �ƴ� �� ���� ���ؼ� 0�� ������ ���
				if (nums[i] != 0 && nums[j] != 0)
				{
					numSet[0].second = true;
				}
				// 0���� ���� ���
				else
				{
					// 0�� ���� �̻� ������ ��� ��� 0�� ��꿡 ���Եȴ�.
					if (numSet[0].first >= 3)
					{
						numSet[0].second = true;
					}
				}
			}
			// ���ؼ� �ڱ� �ڽ��� ������ ���
			else if (sum == nums[i])
			{
				// 2�� �̻� ������ ��� 0�� �ٸ� ���� �������� �ڱ� �ڽ��� ���� �� �ִ�.
				if (numSet[nums[i]].first >= 2)
					numSet[nums[i]].second = true;
			}
			else if (sum == nums[j])
			{
				if (numSet[nums[j]].first >= 2)
					numSet[nums[j]].second = true;
			}
			// �ٸ� ���� ������ ��� -> �ٷ� ��꿡 �߰�
			else
			{
				auto find = numSet.find(sum);

				if (find != numSet.end())
					find->second.second = true;
			}
		}
	}

	for (auto& e : numSet)
	{
		if (e.second.second)
			ans += e.second.first;
	}

	return ans;
}

int main()
{
	cin >> n;
	nums.resize(n);

	for (int i = 0; i < n; ++i) { cin >> nums[i]; }

	cout << solution();

	return 0;
}