// 그리디 알고리즘 >> p.99 1이 될 때까지

#include <iostream>

using namespace std;

int main()
{
	int n, k, ans = 0;

	cin >> n >> k;

	// n 이 k 이상일 경우 계속 나눈다. 
	while (n >= k)
	{
		// 나누어 떨어지는 경우
		if (n % k == 0)
		{
			n /= k;
			++ans;
		}
		// 나누어 떨어지지 않는 경우 배수가 되도록 뺀다.
		else
		{
			ans += n % k;
			n -= n % k;
		}
	}

	ans += n - 1;

	cout << ans;
}