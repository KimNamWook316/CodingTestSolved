#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> map;
vector<pair<int, int>> zeros;
vector<pair<int, int>> virus;

int zeroIndicies[3];
vector<vector<pair<int, int>>> walls;

bool isVoidArea(const vector<vector<int>>& map, const pair<int, int>& idx)
{
	if (idx.first < 0 || idx.first >= n || idx.second < 0 || idx.second >= m)
		return false;

	if (map[idx.first][idx.second] == 0)
		return true;

	return false;
}

// dfs�� ���̷��� ���� ����
void infection(vector<vector<int>>& map, const pair<int, int>& idx)
{
	map[idx.first][idx.second] = 2;

	if (isVoidArea(map, {idx.first - 1, idx.second}))
	{
		infection(map, { idx.first - 1, idx.second });
	}
	if (isVoidArea(map, {idx.first + 1, idx.second}))
	{
		infection(map, { idx.first + 1, idx.second });
	}
	if (isVoidArea(map, {idx.first, idx.second + 1}))
	{
		infection(map, { idx.first, idx.second + 1});
	}
	if (isVoidArea(map, {idx.first, idx.second - 1}))
	{
		infection(map, { idx.first, idx.second - 1});
	}
}

int getSafeArea(const vector<pair<int ,int>>& threeWalls)
{
	vector<vector<int>> curMap = map;

	// �� 3�� ���� ���·� �� ����
	for (const auto& wallIdx : threeWalls)
	{
		curMap[wallIdx.first][wallIdx.second] = 2;
	}

	// ���̷��� ���� ���� (dfs)
	for (const auto& v : virus)
	{
		infection(curMap, v);
	}

	// �������� ���ؼ� ����
	int safeArea = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (curMap[i][j] == 0)
				++safeArea;
		}
	}

	return safeArea;
}

// ���� ���ϱ�
void combination(int depth, int next)
{
	if (depth == 3)
	{
		// �� ���� 3�� �ε���
		vector<pair<int, int>> indicies(3);
		for (int i = 0; i < 3; ++i)
		{
			indicies[i] = zeros[zeroIndicies[i]];
		}
		walls.push_back(indicies);
	}
	else
	{
		for (int i = next; i < zeros.size(); ++i)
		{
			zeroIndicies[depth] = i;

			// ���� ����
			combination(depth + 1, i + 1);
		}
	}
}

int main()
{
	cin >> n >> m;
	map.resize(n);
	for (int i = 0; i < n; ++i)
		map[i].resize(m);

	walls.reserve(map.size());
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];

			if (map[i][j] == 0)
				zeros.push_back({ i, j });
			else if (map[i][j] == 2)
				virus.push_back({ i, j });
		}
	}

	// ���Ʈ ���� : 3���� �� ����� ��� ��� �����
	combination(0, 0);

	// ��� ����� ���� ���� ��� 
	int safeMax = 0;
	for (const auto& combi : walls)
	{
		safeMax = max(safeMax, getSafeArea(combi));
	}

	cout << safeMax;

	return 0;
}
