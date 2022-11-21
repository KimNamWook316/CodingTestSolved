#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int grid[200][200];

// ���̷��� ��ȣ�� ���� ������ ���� �켱������ �ֱ� ������ priority_queue�� ����Ѵ�.
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

			// ���̷����� �ִ� ĭ�� bfsť�� �ִ´�.
			if (0 != grid[i][j])
				bfsQueues.push({ -grid[i][j],{i,j}});
		}
	}

	int s, x, y;
	cin >> s >> x >> y;

	// s�ʵ��� �� �Ͼ� bfs������� ������Ų��.
	for (int i = 0; i < s; ++i)
		infect();

	cout << grid[x - 1][y - 1];

	return 0;
}
