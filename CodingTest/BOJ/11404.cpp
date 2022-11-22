#include <iostream>
#include <vector>

using namespace std;

int n, m;
int graph[101][101];

void floydWarshall()
{
	// 플로이드 워셜
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = 1e9;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b, cost;
		cin >> a >> b >> cost;

		if (graph[a][b] != 0)
			graph[a][b] = min(cost, graph[a][b]);
		else
			graph[a][b] = cost;
	}

	floydWarshall();

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (graph[i][j] == 1e9)
				graph[i][j] = 0;

			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}