#include <iostream>

using namespace std;

int n, x;
int arr[1000000];
int maxIdx, minIdx;

void binSearch(int start, int end)
{
	if (start > end)
		return;

	int mid = (start + end) / 2;

	if (arr[mid] == x)
	{
		if (0 == mid)
		{
			minIdx = mid;
		}
		else if (0 <= mid - 1)
		{
			// 왼쪽에 찾고자 하는 값이 더 있는 경우
			if (x == arr[mid - 1])
			{
				binSearch(start, mid - 1);
			}
			// 왼쪽에 다른 숫자가 있는 경우
			else
			{
				minIdx = mid;
			}
		}

		// 오른쪽에 찾고자 하는 값이 더 있는 경우
		if (n - 1 == mid)
		{
			maxIdx = mid;
		}
		else if (mid + 1 < n)
		{
			if (x == arr[mid + 1])
			{
				binSearch(mid + 1, end);
			}
			else
			{
				maxIdx = mid;
			}
		}
	}
	else
	{
		binSearch(start, mid - 1);
		binSearch(mid + 1, end);
	}
}

int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	maxIdx = n;
	minIdx = -1;

	binSearch(0, n - 1);

	if (maxIdx == n && minIdx == -1)
		cout << -1;
	else
		cout << maxIdx - minIdx + 1;

	return 0;
}