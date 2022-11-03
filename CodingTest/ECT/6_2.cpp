// Sort >> p.178 ������ �Ʒ���

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
		// pivot���� ���� ���� ���� ������
		while (left <= end && pArr[left] > pArr[pivot])
			++left;
		// pivot���� ū ���� ���� ������
		while (right > start && pArr[right] < pArr[pivot])
			--right;

		// ������ ��� pivot ��ü
		if (left > right)
		{
			int temp = pArr[pivot];
			pArr[pivot] = pArr[right];
			pArr[right] = temp;
		}
		// �ƴ� ��� �¿� ��ü => ū ���� ������ ���� �ȴ�.
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
