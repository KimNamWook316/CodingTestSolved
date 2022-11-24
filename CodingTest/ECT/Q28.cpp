#include <iostream>

using namespace std;

int n;
int arr[1000000];
int fixedPoint = -1;

void binSearch(int start, int end)
{
	if (start > end)
		return;

	int mid = (start + end) / 2;

	if (mid == arr[mid])
	{
		fixedPoint = arr[mid];
		return;
	}

	// 인덱스가 수열 원소보다 큰 경우 -> 오른쪽 탐색
	if (mid > arr[mid])
	{
		binSearch(mid + 1, end);
	}
	// 인덱스가 수열 원소보다 작은 경우 -> 왼쪽 탐색
	else
	{
		binSearch(start, mid - 1);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	binSearch(0, n - 1);

	cout << fixedPoint;

	return 0;
}
