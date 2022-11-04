// Binary Search >> p.201 ������ �� ����� 

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

		// middle ������ �߶��� �� ������ ���Ѵ�.
		int acc = 0;
		for (int i = 0; i < n; ++i)
		{
			if (nums[i] - middle > 0)
				acc += nums[i] - middle;
		}

		// �ڸ� ���̰� ���ϴ� ���̺��� ���� ���, �ڸ��� ���� ������ ������.
		if (acc < m)
		{
			end = middle - 1;
		}
		// �ڸ� ���̰� ���ϴ� ���̺��� ũ�ų� ���� ���, �ڸ��� ���� ������ �ø��� ����Ѵ�.
		else
		{
			start = middle + 1;

			// �ִ��� �� �߶��� ���� �����̴�.
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
