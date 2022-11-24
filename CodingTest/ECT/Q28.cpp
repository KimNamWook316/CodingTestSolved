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

	// �ε����� ���� ���Һ��� ū ��� -> ������ Ž��
	if (mid > arr[mid])
	{
		binSearch(mid + 1, end);
	}
	// �ε����� ���� ���Һ��� ���� ��� -> ���� Ž��
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
