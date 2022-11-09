#include <iostream>
#include <vector>

using namespace std;

int n, m;
int table[1001][1001];

void FloydWarshall()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= n; ++k)
				table[j][k] = min(table[j][k], table[j][i] + table[i][k]);
		}
	}
}

int main()
{
	// ��� ����, ���� ����
	cin >> n >> m;

	int start, end, cost;
	for (int i = 0; i < m; ++i)
	{
		cin >> start >> end >> cost;
		table[start][end] = cost;
	}

	// ���̺� �ʱ�ȭ, �ڽſ��� ���� ����� 0, ���� ������ �������� �ʱ�ȭ
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
				table[i][j] = 0;
			else if (table[i][j] == 0)
				table[i][j] = 9999;
		}
	}

	// �÷��̵�-���ȷ� �ִ� ���
	FloydWarshall();

	cout << "Shortest Path :" << endl;
	// �ִ� ��� ���
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << table[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
