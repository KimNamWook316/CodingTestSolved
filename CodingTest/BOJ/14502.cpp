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

// dfs로 바이러스 전염 시작
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

	// 벽 3개 세운 상태로 맵 세팅
	for (const auto& wallIdx : threeWalls)
	{
		curMap[wallIdx.first][wallIdx.second] = 2;
	}

	// 바이러스 전염 시작 (dfs)
	for (const auto& v : virus)
	{
		infection(curMap, v);
	}

	// 안전지역 구해서 리턴
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

// 조합 구하기
void combination(int depth, int next)
{
	if (depth == 3)
	{
		// 벽 세울 3개 인덱스
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

			// 조합 생성
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

	// 브루트 포스 : 3개의 벽 세우는 모든 경우 만들기
	combination(0, 0);

	// 모든 경우의 수에 대한 계산 
	int safeMax = 0;
	for (const auto& combi : walls)
	{
		safeMax = max(safeMax, getSafeArea(combi));
	}

	cout << safeMax;

	return 0;
}
