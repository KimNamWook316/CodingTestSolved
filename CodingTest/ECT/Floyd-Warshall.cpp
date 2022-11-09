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
	// 노드 개수, 간선 개수
	cin >> n >> m;

	int start, end, cost;
	for (int i = 0; i < m; ++i)
	{
		cin >> start >> end >> cost;
		table[start][end] = cost;
	}

	// 테이블 초기화, 자신에게 가는 비용은 0, 간선 없으면 무한으로 초기화
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

	// 플로이드-워셜로 최단 경로
	FloydWarshall();

	cout << "Shortest Path :" << endl;
	// 최단 경로 출력
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
