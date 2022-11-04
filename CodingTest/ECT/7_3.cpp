// Binary Search >> p.201 떡볶이 떡 만들기 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums;

int getLeastH()
{
	int result = -1;
	int start = 0;
	int end = *max_element(nums.begin(), nums.end());

	while (start <= end)
	{
		int middle = (start + end) / 2;

		// middle 값으로 잘랐을 때 총합을 구한다.
		int acc = 0;
		for (int i = 0; i < n; ++i)
		{
			if (nums[i] - middle > 0)
				acc += nums[i] - middle;
		}

		// 자른 길이가 원하는 길이보다 적을 경우, 자르는 길이 기준을 내린다.
		if (acc < m)
		{
			end = middle - 1;
		}
		// 자른 길이가 원하는 길이보다 크거나 같은 경우, 자르는 길이 기준을 올리고 기록한다.
		else
		{
			start = middle + 1;

			// 최대한 덜 잘랐을 때가 정답이다.
			result = middle;
		}
	}
	
	return result;
}

int main()
{
	cin >> n >> m;

	nums.resize(n);
	for (int i = 0; i < n; ++i) { cin >> nums[i]; }

	cout << getLeastH();

	return 0;
}
