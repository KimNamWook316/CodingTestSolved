// �׸��� �˰��� >> p.99 1�� �� ������

#include <iostream>

using namespace std;

int main()
{
	int n, k, ans = 0;

	cin >> n >> k;

	// n �� k �̻��� ��� ��� ������. 
	while (n >= k)
	{
		// ������ �������� ���
		if (n % k == 0)
		{
			n /= k;
			++ans;
		}
		// ������ �������� �ʴ� ��� ����� �ǵ��� ����.
		else
		{
			ans += n % k;
			n -= n % k;
		}
	}

	ans += n - 1;

	cout << ans;
}