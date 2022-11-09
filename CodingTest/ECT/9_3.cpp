// 최단 경로 >> p.262 전보
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int max_cost = 1001;
int n, m;
int table[30001];
vector<pair<int, int>> link[30001];

void dijkstra(int start)
{
	// cost, node
	priority_queue<pair<int, int>> pq;
	table[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (cost > table[current])
			continue;

		for (int i = 0; i < link[current].size(); ++i)
		{
			if (table[link[current][i].first] > cost + link[current][i].second)
			{
				table[link[current][i].first] = cost + link[current][i].second;
				pq.push(make_pair(-table[link[current][i].first], link[current][i].second));
			}
		}
	}
}

int main()
{
	int first;
	cin >> n >> m >> first;

	int start, end, cost;
	for (int i = 0; i < m; ++i)
	{
		cin >> start >> end >> cost;
		link[start].push_back(make_pair(end, cost));
	}

	for (int i = 1; i <= n; ++i)
		table[i] = max_cost;

	dijkstra(first);

	int count = 0;
	int maxDist = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (table[i] != max_cost && table[i] != 0)
		{
			++count;
			maxDist = max(table[i], maxDist);
		}
	}

	cout << count << " " << maxDist;

	return 0;
}
