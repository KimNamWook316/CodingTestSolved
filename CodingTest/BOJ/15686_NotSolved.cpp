#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <numeric>

using namespace std;

int n, m;
int arr[50][50];
vector<int> houses;

static bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
	return lhs.second > rhs.second;
}

int bfs(int index)
{
	queue<int> q;
	q.push(index);

	// idx, prev
	vector<pair<int, int>> visit;

	while (!q.empty())
	{
		int idx = q.front();
		q.pop();

		int row = idx / n;
		int col = idx % n;

		if (arr[row][col] == 3)
			continue;

		if (arr[row][col] == 2)
		{
			for (int i = 0; i < visit.size(); ++i)
			{
				arr[visit[i].first / n][visit[i].first % n] = visit[i].second;
			}
			return idx;
		}

		visit.push_back({idx, arr[row][col]});

		arr[row][col] = 3;

		if (row - 1 >= 0)
		{
			if (arr[row - 1][col] != 3)
			{
				q.push((row - 1) * n + col);
			}
		}

		if (row + 1 < n)
		{
			if (arr[row + 1][col] != 3)
			{
				q.push((row + 1) * n + col);
			}
		}

		if (col - 1 >= 0)
		{
			if (arr[row][col - 1] != 3)
			{
				q.push(row * n + col - 1);
			}
		}

		if (col + 1 < n)
		{
			if (arr[row][col + 1] != 3)
			{
				q.push(row * n + col + 1);
			}
		}
	}

	for (int i = 0; i < visit.size(); ++i)
	{
		arr[visit[i].first / n][visit[i].first % n] = visit[i].second;
	}

	return -1;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 1)
			{
				houses.push_back(i * n + j);
			}
		}
	}

	// i * n + j = �ε���, house���� ���ù��� ��
	map<int, int> map;
	for (int i = 0; i < houses.size(); ++i)
	{
		int chicken = bfs(houses[i]);

		map[chicken] += 1;
	}

	// ���ͷ� �Űܼ� house���� ���� ���ù��� ������ ����
	vector<pair<int, int>> vec(map.begin(), map.end());
	sort(vec.begin(), vec.end(), cmp);

	vector<int> lastCost(houses.size(), 1e9);

	// ���õ� ġŲ���� ���ڰ� ���� �� ���ں��� ���� ���
	if (vec.size() <= m)
	{
		for (const auto& c : vec)
		{
			int row = c.first / n;
			int col = c.first % n;

			for (int i = 0; i < houses.size(); ++i)
			{
				int hRow = houses[i] / n;
				int hCol = houses[i] % n;
				lastCost[i] = min(lastCost[i], abs(row - hRow) + abs(col - hCol));
			}
		}
	}
	// ������Ѿ� �ϴ� ���
	else
	{
		// ��� ���� ���� ġŲ �Ÿ� �ջ�, ġŲ�� �ε���
		vector<pair<int, int>> vecCost(vec.size());
		for (int i = 0; i < vec.size(); ++i)
		{
			// �ε���
			vecCost[i].second = vec[i].first;

			int row = vec[i].first / n;
			int col = vec[i].second % n;

			// �Ÿ� �ջ�
			for (const auto& h : houses)
			{
				int hRow = h / n;
				int hCol = h % n;
				vecCost[i].first += abs(row - hRow) + abs(col - hCol);
			}
		}

		// ġŲ �Ÿ� ������������ �ĺ� ����
		sort(vecCost.begin(), vecCost.end());

		// �Ÿ��� ���� �� m���� �̾Ƽ� �ִܰŸ� ���
		for (int i = 0; i < m; ++i)
		{
			int row = vecCost[i].second / n;
			int col = vecCost[i].second % n;

			for (int j = 0; j < houses.size(); ++j)
			{
				int hRow = houses[j] / n;
				int hCol = houses[j] % n;
				lastCost[j] = min(lastCost[j], abs(row - hRow) + abs(col - hCol));
			}
		}
	}

	// �Ÿ� �ջ�
	int ans = accumulate(lastCost.begin(), lastCost.end(), 0);
	cout << ans;

	return 0;
}