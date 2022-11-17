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

	// 0이 존재하는가 : 최적화
	bool zero = false;
	
	// 숫자, <등장횟수, 계산 포함 여부>
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

			// 더해서 0이 나오는 경우에 대한 처리
			if (zero && sum == 0)
			{
				// 0이 아닌 두 수를 더해서 0이 나오는 경우
				if (nums[i] != 0 && nums[j] != 0)
				{
					numSet[0].second = true;
				}
				// 0끼리 더한 경우
				else
				{
					// 0이 세번 이상 등장한 경우 모든 0은 계산에 포함된다.
					if (numSet[0].first >= 3)
					{
						numSet[0].second = true;
					}
				}
			}
			// 더해서 자기 자신이 나오는 경우
			else if (sum == nums[i])
			{
				// 2번 이상 등장할 경우 0과 다른 수의 조합으로 자기 자신을 만들 수 있다.
				if (numSet[nums[i]].first >= 2)
					numSet[nums[i]].second = true;
			}
			else if (sum == nums[j])
			{
				if (numSet[nums[j]].first >= 2)
					numSet[nums[j]].second = true;
			}
			// 다른 수가 나오는 경우 -> 바로 계산에 추가
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