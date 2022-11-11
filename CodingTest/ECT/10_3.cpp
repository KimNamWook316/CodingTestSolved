// �׷��� �̷� >> p.300 ���� ���� ��ȹ
#include <iostream>
#include <map>

using namespace std;

// ��� ����, ���� ����
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

	// �θ� ���̺� �ʱ�ȭ
	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	// �Է�
	multimap<int, pair<int, int>> edges;
	int a, b, cost;
	for (int i = 0; i < m ; ++i)
	{
		cin >> a >> b >> cost;

		// cost ������������ ����
		edges.insert(make_pair(cost, make_pair(a, b)));
	}

	int maxCost = -1;
	int ans = 0;

	// �ּ� ���� Ʈ�� �Ǻ�
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

	// ������ �ּ� ���� Ʈ������ ���� ����� ū ������ �������ָ� �� �� ������ ���еȴ�.
	ans -= maxCost;
	cout << ans;

	return 0;
}
