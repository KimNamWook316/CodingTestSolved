// Dynamic Programming >> p.226 효율적인 화폐 구성

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

	// 초기화
	d = new int[m + 1];
	for (int i = 0; i < m + 1; ++i)
		d[i] = 10001;
	d[0] = 0;

	for (int i = 0; i < n; ++i)
	{
		// 화폐 단위별로 금액을 만들 수 있는 경우를 계산한다.
		for (int j = arr[i]; j <= m; ++j)
		{
			// A(i-k) != 10001이면 계산된 값이 있다.
			// 기존에 계산된 값과 비교하여 작으면 교체
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
