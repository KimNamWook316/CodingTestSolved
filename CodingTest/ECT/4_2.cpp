// 구현 >> p.115 왕실의 나이트

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int moveX[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int moveY[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

	string pos;
	cin >> pos;

	int ans = 0;

	for (int i = 0; i < 8; ++i)
	{
		int x = static_cast<int>(pos[0] - 'a' + 1);
		int y = static_cast<int>(pos[1] - '0');

		if (x + moveX[i] > 0 && y + moveY[i] > 0)
			++ans;
	}

	cout << ans;

	return 0;
}
