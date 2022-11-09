// �ִ� ��� >> p.259 �̷� ����

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// ��� ����, ���� ����, ���� ��ǥ��, �߰� ��ǥ��
int n, m, x, k;
int table[101][101];

void floydwarshall()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
				table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	int n1, n2;
	for (int i = 0; i < m; ++i)
	{
		cin >> n1 >> n2;
		table[n1][n2] = 1;
		table[n2][n1] = 1;
	}

	cin >> x >> k;

	// ���̺� �ʱ�ȭ
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
				table[i][j] = 0;
			else if (table[i][j] == 0)
				table[i][j] = 99999;
		}
	}

	floydwarshall();

	if (table[1][k] == 99999 || table[k][x] == 99999)
		cout << -1;
	else
		cout << table[1][k] + table[k][x];

	return 0;
}