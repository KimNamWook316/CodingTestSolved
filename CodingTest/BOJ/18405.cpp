#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int grid[200][200];

// 바이러스 번호가 작은 순으로 전염 우선순위가 있기 때문에 priority_queue를 사용한다.
priority_queue<pair<int, pair<int, int>>> bfsQueues;

bool isValidIndex(int i, int j, int v)
{
	if (i < 0 || j < 0 || i >= n || j >= n)
		return false;

	if (0 == grid[i][j])
		return true;

	return false;
}

void infect()
{
	priority_queue<pair<int, pair<int, int>>> newQ;

	while (!bfsQueues.empty())
	{
		int virus = -bfsQueues.top().first;
		pair<int, int> index = bfsQueues.top().second;
		bfsQueues.pop();

		if (isValidIndex(index.first - 1, index.second, virus))
		{
			grid[index.first - 1][index.second] = virus;
			newQ.push({ -virus, {index.first - 1, index.second} });
		}
		if (isValidIndex(index.first + 1, index.second, virus))
		{
			grid[index.first + 1][index.second] = virus;
			newQ.push({ -virus, {index.first + 1, index.second} });
		}
		if (isValidIndex(index.first	, index.second - 1, virus))
		{
			grid[index.first][index.second - 1] = virus;
			newQ.push({ -virus, {index.first, index.second - 1} });
		}
		if (isValidIndex(index.first, index.second + 1, virus))
		{
			grid[index.first][index.second + 1] = virus;
			newQ.push({ -virus, {index.first, index.second + 1} });
		}
	}

	bfsQueues = newQ;
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> grid[i][j];

			// 바이러스가 있는 칸은 bfs큐에 넣는다.
			if (0 != grid[i][j])
				bfsQueues.push({ -grid[i][j],{i,j}});
		}
	}

	int s, x, y;
	cin >> s >> x >> y;

	// s초동안 한 턴씩 bfs방식으로 전염시킨다.
	for (int i = 0; i < s; ++i)
		infect();

	cout << grid[x - 1][y - 1];

	return 0;
}
