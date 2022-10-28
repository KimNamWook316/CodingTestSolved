// ���� >> p.118 ���� ���� 

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
		// �� ���� ��� �� �� ���� ���
		if (cnt == 4)
		{
			// �ڵ� �ٴ��� ��� ��
			if (map[player.y + dirY[player.dir] * -1][player.x + dirX[player.dir] * -1] == 1)
				break;
			// �ڷ� �̵�
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

		// �������� ����
		nextDir = player.dir - 1 >= 0 ? player.dir - 1 : 3;

		int nX = dirX[nextDir] + player.x;
		int nY = dirY[nextDir] + player.y;

		player.dir = nextDir;
		++cnt;

		// ����ó��
		if (nX < 0 || nY < 0)
			continue;

		// �� �� �ִ� ���
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
