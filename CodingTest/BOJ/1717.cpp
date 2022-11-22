#include <iostream>

using namespace std;

int n, m;
int parent[1000001];

int find_parent(int i)
{
	if (i != parent[i])
		parent[i] = find_parent(parent[i]);

	return parent[i];
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; ++i)
		parent[i] = i;

	for (int i = 0; i < m; ++i)
	{
		int op, a, b;
		cin >> op >> a >> b;

		if (0 == op)
		{
			union_parent(a, b);
		}
		else if (1 == op)
		{
			if (find_parent(a) == find_parent(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}
