// 그래프 이론 >> p.300 도시 분할 계획
#include <iostream>
#include <map>

using namespace std;

// 노드 개수, 간선 개수
int n, m;
int parent[100001];

int find_Parent(int v)
{
	if (v != parent[v])
		parent[v] = find_Parent(parent[v]);

	return parent[v];
}

void union_Parent(int a, int b)
{
	a = find_Parent(a);
	b = find_Parent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

bool is_Cycle(int a, int b)
{
	if (find_Parent(a) == find_Parent(b))
		return true;

	return false;
}

int main()
{
	cin >> n >> m;

	// 부모 테이블 초기화
	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	// 입력
	multimap<int, pair<int, int>> edges;
	int a, b, cost;
	for (int i = 0; i < m ; ++i)
	{
		cin >> a >> b >> cost;

		// cost 오름차순으로 정렬
		edges.insert(make_pair(cost, make_pair(a, b)));
	}

	int maxCost = -1;
	int ans = 0;

	// 최소 신장 트리 판별
	for(const auto& e : edges)
	{
		if (is_Cycle(e.second.first, e.second.second))
			continue;
		else
		{
			if (maxCost < e.first)
				maxCost = e.first;

			union_Parent(e.second.first, e.second.second);

			ans += e.first;
		}
	}

	// 구성된 최소 신장 트리에서 가장 비용이 큰 간선을 제거해주면 두 개 마을로 구분된다.
	ans -= maxCost;
	cout << ans;

	return 0;
}
