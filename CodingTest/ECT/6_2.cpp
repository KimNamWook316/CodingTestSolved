// Sort >> p.178 위에서 아래로

#include <iostream>

using namespace std;

int arr[500] = {};

void quicksort(int* pArr, int start, int end)
{
	if (start >= end)
		return;

	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left < right)
	{
		// pivot보다 작은 수가 나올 때까지
		while (left <= end && pArr[left] > pArr[pivot])
			++left;
		// pivot보다 큰 수가 나올 때까지
		while (right > start && pArr[right] < pArr[pivot])
			--right;

		// 엇갈린 경우 pivot 교체
		if (left > right)
		{
			int temp = pArr[pivot];
			pArr[pivot] = pArr[right];
			pArr[right] = temp;
		}
		// 아닌 경우 좌우 교체 => 큰 수가 앞으로 오게 된다.
		else
		{
			int temp = pArr[right];
			pArr[right] = pArr[left];
			pArr[left] = pArr[right];
		}
	}

	quicksort(pArr, start, pivot - 1);
	quicksort(pArr, pivot + 1, end);
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) { cin >> arr[i];}

	quicksort(arr, 0, n - 1);

	for (int i = 0; i < n; ++i) { cout << arr[i] << " "; }

	return 0;
}
