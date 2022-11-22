#include <iostream>
#include <queue>

using namespace std;

int n, m;
int parent[10001];
priority_queue<pair<int, pair<int, int>>> q;

int find_parent(int x)
{
	if (parent[x] != x)
	{
		parent[x] = find_parent(parent[x]);
	}
	return parent[x];
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int kruskal()
{
	int ans = 0;

	while(!q.empty())
	{
		int cost = -q.top().first;
		int a = q.top().second.first;
		int b = q.top().second.second;
		q.pop();

		if (find_parent(a) != find_parent(b))
		{
			union_parent(a, b);
			ans += cost;
		}
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	// �θ� ���̺� �ʱ�ȭ
	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	// ���� ���� �Է�
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		q.push({ -c, {a, b} });
	}

	// ũ�罺Į �˰������� �ּ� ���� Ʈ�� ����ġ ����
	cout << kruskal();

	return 0;
}