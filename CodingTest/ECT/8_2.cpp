// Dynamic Programming >> p.217 1�� �����

#include <iostream>

using namespace std;

// �� ��� : ž�ٿ� ���
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


// å ���� : ���Ҿ� ���
int dpTable[30001];

int MySolve(int x)
{
	for (int i = 2; i < x + 1; ++i)
	{
		// f(i-1)���� 1�� ���� ����� ī��Ʈ
		dpTable[i] = dpTable[i - 1] + 1;

		// f(i)���� f(i/2)�� ���� ����� ī��Ʈ�� ��
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

	// �� ���
	MySolve(i);
	cout << least << endl;

	int ans = MySolve(i);
	cout << ans;

	return 0;
}
