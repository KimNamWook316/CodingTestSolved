// 구현 >> p.118 게임 개발 

#include <iostream>
#include <vector>

using namespace std;

struct PlayerInfo
{
	int x;
	int y;
	int dir;
};

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, 1, 0, -1 };

int main()
{
	PlayerInfo player;

	int n, m, buf;
	cin >> n >> m;

	vector<vector<int>> map(n);
	for (int i = 0; i < n; ++i)
		map[i].resize(m);

	cin >> player.x >> player.y >> player.dir;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
		}
	}

	int ans = 0;
	int cnt = 0;
	while (true)
	{
		// 네 방향 모두 갈 수 없는 경우
		if (cnt == 4)
		{
			// 뒤도 바다인 경우 끝
			if (map[player.y + dirY[player.dir] * -1][player.x + dirX[player.dir] * -1] == 1)
				break;
			// 뒤로 이동
			else
			{
				map[player.y][player.x] = 3;
				player.x = player.x + dirX[player.dir] * -1;
				player.y = player.y + dirY[player.dir] * -1;
				++ans;
				cnt = 0;
				continue;
			}
		}

		int nextDir = 0;

		// 왼쪽으로 돈다
		nextDir = player.dir - 1 >= 0 ? player.dir - 1 : 3;

		int nX = dirX[nextDir] + player.x;
		int nY = dirY[nextDir] + player.y;

		player.dir = nextDir;
		++cnt;

		// 예외처리
		if (nX < 0 || nY < 0)
			continue;

		// 갈 수 있는 경우
		if (map[nY][nX] == 0)
		{
			map[player.y][player.x] = 3;
			player.x = nX;
			player.y = nY;
			cnt = 0;
			++ans;
		}
	}

	cout << ans;

	return 0;
}
