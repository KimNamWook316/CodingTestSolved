// DFS/BFS >> p.149 음료수 얼려 먹기

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// N, E, S, W
int dirX[4] = { 0, 1, 0, -1 };
int dirY[4] = { -1, 0, 1, 0 };

int bfs(vector<vector<int>>& maze)
{
	int depth = 0;
	queue<pair<int, int>> xyQueue;
	xyQueue.push(make_pair(0, 0));

	while (!xyQueue.empty())
	{
		pair<int, int> idx = xyQueue.front();
		xyQueue.pop();
		depth = maze[idx.second][idx.first];
		maze[idx.second][idx.first] = -1;

		for (int i = 0; i < 4; ++i)
		{
			pair<int, int> adjIdx = make_pair(idx.first + dirX[i], idx.second + dirY[i]);

			if (adjIdx.first < 0 || adjIdx.second < 0 || 
				adjIdx.first >= maze[0].size() || adjIdx.second >= maze.size())
				continue;

			// 목표에 도달한 경우 최단거리 리턴
			if (adjIdx.first == maze[0].size() - 1 && adjIdx.second == maze.size() - 1)
				return depth + 1;

			// 방문하지 않았던 노드에만 거리 계산
			if (maze[adjIdx.second][adjIdx.first] == 1)
			{
				xyQueue.push(make_pair(adjIdx.first, adjIdx.second));
				maze[adjIdx.second][adjIdx.first] = depth + 1;
			}
		}
	}
	return -1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	cin.ignore();

	vector<vector<int>> maze(n);
	for (int i = 0; i < n; ++i)
	{
		maze[i].resize(m);
		for (int j = 0; j < m; ++j)
		{
			scanf_s("%1d", &maze[i][j]);
		}
	}

	int ans = bfs(maze);
	cout << ans;

	return 0;
}
