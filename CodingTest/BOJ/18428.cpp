#include <iostream>
#include <vector>

using namespace std;

#define E 0
#define S 1
#define W 2 
#define N 3 

int n;
vector<vector<char>> map;
vector<pair<int, int>> vecVoid;
vector<pair<int, int>> vecTeacher;

// ����� ��
int tempIdx[3];
vector<vector<int>> vecObstacleIdx;

bool find(const vector<vector<char>>& tmpMap, int row, int col, int dir)
{
	if (row < 0 || row >= n || col < 0 || col >= n)
		return false;

	if (tmpMap[row][col] == 'O')
		return false;

	if (tmpMap[row][col] == 'S')
		return true;

	switch (dir)
	{
	case E:
		return find(tmpMap, row, col + 1, dir);
	case S:
		return find(tmpMap, row + 1, col, dir);
	case W:
		return find(tmpMap, row, col - 1, dir);
	case N:
		return find(tmpMap, row - 1, col, dir);
	}
}

bool test(const vector<int>& obstacleIndicies)
{
	vector<vector<char>> tempMap = map;

	// �ӽ� ��ֹ� ��ġ
	for (const int& idx : obstacleIndicies)
	{
		tempMap[vecVoid[idx].first][vecVoid[idx].second] = 'O';
	}

	// �����Ը��� �����¿� Ž��, �л� �ϳ��� ã�Ҵٸ� ����
	for (const pair<int,int>& teacher : vecTeacher)
	{
		int row = teacher.first;
		int col = teacher.second;

		if (find(tempMap, row, col + 1, E))
			return false;

		if (find(tempMap, row + 1, col, S))
			return false;

		if (find(tempMap, row, col - 1, W))
			return false;

		if (find(tempMap, row - 1, col, N))
			return false;
	}

	// ��� ������ �þ� Ž������ �л��� �߰ߵ��� �ʾҴٸ�
	return true;
}

void combination(int depth, int next)
{
	if (3 == depth)
	{
		vector<int> vecIdx(3);
		for (int i = 0; i < 3; ++i)
			vecIdx[i] = tempIdx[i];
		vecObstacleIdx.emplace_back(vecIdx);
	}
	else
	{
		for (int i = next; i < vecVoid.size(); ++i)
		{
			tempIdx[depth] = i;
			combination(depth + 1, i + 1);
		}
	}
}

int main()
{
	cin >> n;
	map.resize(n);
	for (int i = 0; i < n; ++i)
	{
		map[i].resize(n);
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];

			if ('X' == map[i][j])
			{
				vecVoid.push_back({ i, j });
			}
			else if ('T' == map[i][j])
			{
				vecTeacher.push_back({ i, j });
			}
		}
	}

	// ��� ��ֹ� ��ġ ����� �� ���ϱ�
	combination(0, 0);

	for (const auto& obstacles : vecObstacleIdx)
	{
		if (test(obstacles))
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}