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

// 시간 복잡도 O(노드개수^2)
void EasyDijkstra(int start)
{
	table[start] = 0;

	// O(V)
	for (int i = 0; i < n; ++i)
	{
		// 현재 방문하지 않은 노드들 중에서 가장 최단경로인 노드를 찾는다. 
		// O(V)
		int smallest = GetSmallestCostNode();
		visited[smallest] = true;

		// 현재 선택된 노드와 연결된 노드를 탐색
		for (int j = 0; j < link[smallest].size(); ++j)
		{
			// 현재 노드에서 연결된 노드로 갈 수 있는 거리
			int cost = table[smallest] + link[smallest][j].second;

			// 테이블에 기록된 값보다 적다면 갱신
			if (cost < table[link[smallest][j].first])
				table[link[smallest][j].first] = cost;
		}
	}
}

// 시간 복잡도 O(간선개수 * log(노드개수))
void AdvancedDijkstra(int start)
{
	// pair<int, int> : <거리, 목표노드>
	std::priority_queue <pair<int, int>>pq;

	// 시작 노드까지 가는 경로 0으로 설정하고 큐에 삽입
	table[start] = 0;
	pq.push(make_pair(0, start));

	// 큐가 비어있지 않다면
	while (!pq.empty())
	{
		// priority queue는 기본적으로 내림차순 정렬되어 있으므로
		// 오름차순 정렬하기 위해 -를 붙여 큐에 넣어놓는다.
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		// 이미 처리된 적이 있는 노드라면 무시한다.
		if (table[now] < dist)
			continue;

		// 현재 노드와 연결된 인접 노드 확인
		for (int i = 0; i < link[now].size(); ++i)
		{
			int cost = dist + link[now][i].second;

			// 현재 노드를 거쳐 다른 노드로 이동하는 경로가 더 짧을 경우
			// 테이블 갱신하고 큐에 갱신 정보 넣는다.
			if (cost < table[link[now][i].first])
			{
				table[link[now][i].first] = cost;

				// 오름차순 정렬을 위해 -부호 붙여서 삽입
				pq.push(make_pair(-cost, link[now][i].first));
			}
		}
	}
}

int main()
{
	// 노드 개수, 간선 개수, 출발 노드
	int startIndex;
	cin >> n >> m >> startIndex;

	table[0] = INT_MAX;
	for (int i = 1; i <= n; ++i)
	{
		visited[i] = false;
		table[i] = INT_MAX;
	}

	// 간선 정보 생성
	int start, end, cost;
	for (int i = 0; i < m; ++i)
	{
		cin >> start >> end >> cost;
		link[start].push_back(make_pair(end, cost));
	}

	// 최단 경로 구하기
	// EasyDijkstra(startIndex);
	AdvancedDijkstra(startIndex);

	// 1에서 출발했을 때의 최단 경로 값 출력
	for (int i = 1; i <= n; ++i)
		cout << "1 To " << i << " : " << table[i] << endl;

	return 0;
}