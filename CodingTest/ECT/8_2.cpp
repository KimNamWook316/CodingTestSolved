// Dynamic Programming >> p.217 1로 만들기

#include <iostream>

using namespace std;

// 내 답안 : 탑다운 방식
int least = INT_MAX;
void MySolve(int x, int count = 0)
{
	if (count > least)
		return;

	if (1 == x)
	{
		least = count;
		return;
	}

	if (0 == (x % 5))
		MySolve(x / 5, count + 1);

	if (0 == (x % 3))
		MySolve(x / 3, count + 1);

	if (0 == (x % 2))
		MySolve(x / 2, count + 1);

	MySolve(x - 1, count + 1);
}


// 책 정답 : 바텀업 방식
int dpTable[30001];

int MySolve(int x)
{
	for (int i = 2; i < x + 1; ++i)
	{
		// f(i-1)에서 1을 더한 경우의 카운트
		dpTable[i] = dpTable[i - 1] + 1;

		// f(i)에서 f(i/2)로 가는 경우의 카운트와 비교
		if (0 == (i % 2))
			dpTable[i] = min(dpTable[i], dpTable[i / 2] + 1);

		if (0 == (i % 3))
			dpTable[i] = min(dpTable[i], dpTable[i / 3] + 1);

		if (0 == (i % 5))
			dpTable[i] = min(dpTable[i], dpTable[i / 5] + 1);
	}

	return dpTable[x];
}

int main()
{
	int i;
	cin >> i;

	// 내 답안
	MySolve(i);
	cout << least << endl;

	int ans = MySolve(i);
	cout << ans;

	return 0;
}
