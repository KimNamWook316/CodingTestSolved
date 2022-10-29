// DFS/BFS >> p.149 음료수 얼려 먹기

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// N, E, S, W
int dirX[4] = { 0, 1, 0, -1 };
int dirY[4] = { -1, 0, 1, 0 };
int** tray = nullptr;
int n, m, answer;

void bfs(int x, int y)
{
	if (tray[y][x] != 0)
		return;

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		pair<int, int> idx = q.front();
		q.pop();
		tray[idx.second][idx.first] = 3;

		for (int i = 0; i < 4; ++i)
		{
			int idxX = idx.first + dirX[i];
			int idxY = idx.second + dirY[i];

			if (idxX < 0 || idxY < 0 || idxX >= m || idxY == n)
				continue;

			if (tray[idx.second + dirY[i]][idx.first + dirX[i]] == 0)
				q.push(make_pair(idx.first + dirX[i], idx.second + dirY[i]));
		}
	}

	++answer;
}

bool dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= m || y >= n)
		return false;

	if (tray[y][x] == 1)
		return false;

	tray[y][x] = 1;

	dfs(x, y - 1);
	dfs(x, y + 1);
	dfs(x - 1, y);
	dfs(x + 1, y);

	return true;
}

int main()
{
	cin >> n >> m;

	tray = new int* [n];
	for (int i = 0; i < n; ++i)
		tray[i] = new int[m];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf_s("%1d", &tray[i][j]);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			// bfs(j, i);
			if (dfs(j, i))
				++answer;
		}
	}

	cout << answer;

	for (int i = 0; i < n; ++i)
	{
		delete tray[i];
		tray[i] = nullptr;
	}
	delete[] tray;
	tray = nullptr;

	return 0;
}
