// Dynamic Programming >> p.226 ȿ������ ȭ�� ����

#include <iostream>
#include <memory>

using namespace std;

int main()
{
	int n, m;
	int arr[100];

	int* d = nullptr;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	// �ʱ�ȭ
	d = new int[m + 1];
	for (int i = 0; i < m + 1; ++i)
		d[i] = 10001;
	d[0] = 0;

	for (int i = 0; i < n; ++i)
	{
		// ȭ�� �������� �ݾ��� ���� �� �ִ� ��츦 ����Ѵ�.
		for (int j = arr[i]; j <= m; ++j)
		{
			// A(i-k) != 10001�̸� ���� ���� �ִ�.
			// ������ ���� ���� ���Ͽ� ������ ��ü
			if (d[j - arr[i]] != 10001)
				d[j] = min(d[j], d[j - arr[i]] + 1);
		}
	}

	if (d[m] == 10001)
		cout << -1;
	else
		cout << d[m];

	delete[] d;

	return 0;
}
