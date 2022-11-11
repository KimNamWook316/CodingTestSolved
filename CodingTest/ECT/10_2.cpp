// �׷��� �̷� >> p.298 �� �Ἲ

#include <iostream>

using namespace std;

int n, m;
int parent[100001];

int findParent(int a)
{
	if (parent[a] != a)
		parent[a] = findParent(parent[a]);

	return parent[a];
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

bool isSameTeam(int a, int b)
{
	if (findParent(a) == findParent(b))
		return true;

	return false;
}

int main()
{
	cin >> n >> m;

	// �θ� ���̺� �ʱ�ȭ
	for (int i = 0; i <= n; ++i)
		parent[i] = i;

	int op, a, b;
	// ������ ����
	for (int i = 0; i <m; ++i)
	{
		cin >> op >> a >> b;

		if (0 == op)
		{
			unionParent(a, b);
		}
		else
		{
			if (isSameTeam(a, b))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}
