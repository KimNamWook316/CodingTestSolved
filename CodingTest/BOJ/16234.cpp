#include <iostream>
#include <vector>

using namespace std;

int n, l, r;
int graph[50][50];
bool check[50][50];
int groupCount = 0;

void dfs(vector<pair<int, int>>& alli, int prev, int& sum, int row, int col)
{
	if (row < 0 || col < 0 || row >= n || col >= n)
		return;

	if (check[row][col])
		return;

	int diff = abs(graph[row][col] - prev);

	if (diff < l || diff > r)
		return;

	sum += graph[row][col];
	alli.push_back({ row, col });
	check[row][col] = true;

	dfs(alli,graph[row][col], sum, row - 1, col);
	dfs(alli, graph[row][col], sum, row + 1, col);
	dfs(alli, graph[row][col], sum, row, col - 1);
	dfs(alli, graph[row][col], sum ,row, col + 1);
}

void startSearch(vector<pair<int, int>>& alli, int& sum, int row, int col)
{
	sum += graph[row][col];
	alli.push_back({ row, col });
	check[row][col] = true;

	dfs(alli,graph[row][col], sum, row - 1, col);
	dfs(alli, graph[row][col], sum, row + 1, col);
	dfs(alli, graph[row][col], sum, row, col - 1);
	dfs(alli, graph[row][col], sum ,row, col + 1);
}

int solution()
{
	int day = 0;

	while(groupCount != n * n)
	{
		groupCount = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (check[i][j])
					continue;

				vector<pair<int, int>> alliance;
				int sum = 0;
				startSearch(alliance, sum, i, j);

				int groupSize = alliance.size();
				++groupCount;
				int avg = sum / groupSize;

				for (const auto& e : alliance)
				{
					graph[e.first][e.second] = avg;
				}
			}
		}

		if (groupCount == n * n)
			return day;

		++day;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				check[i][j] = false;
			}
		}
	}

	return day;
}

int main()
{
	cin >> n >> l >> r;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> graph[i][j];
		}
	}

	int ans = solution();
	cout << ans;

	return 0;
}