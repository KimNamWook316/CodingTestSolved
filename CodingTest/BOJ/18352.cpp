#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, x;
vector<vector<int>> link;

void dijkstra(vector<int>& table, int start)
{
	vector<bool> visited(n + 1, false);
	priority_queue<pair<int, int>> pq;
	table[start] = 0;
	pq.push({0, start});

	while(!pq.empty())
	{
		pair<int, int> info = pq.top();
		pq.pop();

		if (visited[info.second])
			continue;

		visited[info.second] = true;

		for(const auto& i : link[info.second])
		{
			int cost = -info.first + 1;

			if (cost < table[i])
			{
				table[i] = cost;
				pq.push({ -cost, i });
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k >> x;

	vector<int> table(n + 1, 1e9);

	link.resize(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int s, e;
		cin >> s >> e;
		link[s].push_back(e);
	}

	dijkstra(table, x);

	bool exist = false;
	for (int i = 1; i <= n; ++i)
	{
		if (k == table[i])
		{
			if (!exist)
				exist = true;

			cout << i << "\n";
		}
	}

	if (!exist)
		cout << -1;

	return 0;
}