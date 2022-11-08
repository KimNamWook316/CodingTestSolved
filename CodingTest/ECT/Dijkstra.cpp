#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int n, m;
bool visited[1001];
int table[1001];
vector<pair<int, int>> link[1001];

int GetSmallestCostNode()
{
	int smallest = INT_MAX;
	int index = -1;
	for (int i = 0; i < n; ++i)
	{
		if (smallest > table[i] && !visited[i])
		{
			smallest = table[i];
			index = i;
		}
	}

	return index;
}

// �ð� ���⵵ O(��尳��^2)
void EasyDijkstra(int start)
{
	table[start] = 0;

	// O(V)
	for (int i = 0; i < n; ++i)
	{
		// ���� �湮���� ���� ���� �߿��� ���� �ִܰ���� ��带 ã�´�. 
		// O(V)
		int smallest = GetSmallestCostNode();
		visited[smallest] = true;

		// ���� ���õ� ���� ����� ��带 Ž��
		for (int j = 0; j < link[smallest].size(); ++j)
		{
			// ���� ��忡�� ����� ���� �� �� �ִ� �Ÿ�
			int cost = table[smallest] + link[smallest][j].second;

			// ���̺� ��ϵ� ������ ���ٸ� ����
			if (cost < table[link[smallest][j].first])
				table[link[smallest][j].first] = cost;
		}
	}
}

// �ð� ���⵵ O(�������� * log(��尳��))
void AdvancedDijkstra(int start)
{
	// pair<int, int> : <�Ÿ�, ��ǥ���>
	std::priority_queue <pair<int, int>>pq;

	// ���� ������ ���� ��� 0���� �����ϰ� ť�� ����
	table[start] = 0;
	pq.push(make_pair(0, start));

	// ť�� ������� �ʴٸ�
	while (!pq.empty())
	{
		// priority queue�� �⺻������ �������� ���ĵǾ� �����Ƿ�
		// �������� �����ϱ� ���� -�� �ٿ� ť�� �־���´�.
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		// �̹� ó���� ���� �ִ� ����� �����Ѵ�.
		if (table[now] < dist)
			continue;

		// ���� ���� ����� ���� ��� Ȯ��
		for (int i = 0; i < link[now].size(); ++i)
		{
			int cost = dist + link[now][i].second;

			// ���� ��带 ���� �ٸ� ���� �̵��ϴ� ��ΰ� �� ª�� ���
			// ���̺� �����ϰ� ť�� ���� ���� �ִ´�.
			if (cost < table[link[now][i].first])
			{
				table[link[now][i].first] = cost;

				// �������� ������ ���� -��ȣ �ٿ��� ����
				pq.push(make_pair(-cost, link[now][i].first));
			}
		}
	}
}

int main()
{
	// ��� ����, ���� ����, ��� ���
	int startIndex;
	cin >> n >> m >> startIndex;

	table[0] = INT_MAX;
	for (int i = 1; i <= n; ++i)
	{
		visited[i] = false;
		table[i] = INT_MAX;
	}

	// ���� ���� ����
	int start, end, cost;
	for (int i = 0; i < m; ++i)
	{
		cin >> start >> end >> cost;
		link[start].push_back(make_pair(end, cost));
	}

	// �ִ� ��� ���ϱ�
	// EasyDijkstra(startIndex);
	AdvancedDijkstra(startIndex);

	// 1���� ������� ���� �ִ� ��� �� ���
	for (int i = 1; i <= n; ++i)
		cout << "1 To " << i << " : " << table[i] << endl;

	return 0;
}