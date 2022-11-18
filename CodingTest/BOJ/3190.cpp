#include <iostream>
#include <deque>
#include <queue>

using namespace std;

#define VOID	0
#define BODY	1
#define APPLE	2

#define TURN_LEFT	'L'
#define TURN_RIGHT	'D'

#define DIR_E 0
#define DIR_S 1
#define DIR_W 2 
#define DIR_N 3

int N, K, L;
vector<vector<int>> gameMap;
queue<pair<int, char>> dirQ;

struct Snake
{
	deque<pair<int, int>> Body;
	int Direction;
};

int game()
{
	int time = 0;
	Snake snake;
	snake.Body.push_back({ 0,0 });
	snake.Direction = DIR_E;

	gameMap[0][0] = BODY;

	while (true)
	{
		++time;

		// 현재 머리의 위치
		pair<int, int> head = snake.Body.front();

		// 머리의 위치를 진행방향으로
		switch (snake.Direction)
		{
		case DIR_E:
			++head.second;
			break;
		case DIR_S:
			++head.first;
			break;
		case DIR_W:
			--head.second;
			break;
		case DIR_N:
			--head.first;
			break;
		}

		// 벽을 만난 경우 종료
		if (head.first < 0 ||
			head.first >= N ||
			head.second < 0 ||
			head.second >= N)
			break;

		// 진행 방향에 몸이 있으면 종료
		if (gameMap[head.first][head.second] == BODY)
			break;

		// 머리 이동
		snake.Body.push_front({ head.first, head.second });

		// 사과가 없는 경우 꼬리 삭제
		if (gameMap[head.first][head.second] != APPLE)
		{
			// 맵에 기록
			pair<int, int> tail = snake.Body.back();

			// 맵에 기록
			gameMap[tail.first][tail.second] = VOID;

			// 꼬리 삭제
			snake.Body.pop_back();
		}

		// 맵에 기록
		gameMap[head.first][head.second] = BODY;

		// 방향 전환해야 하는지 고려
		if (!dirQ.empty())
		{
			pair<int, char> dirChange = dirQ.front();

			// 방향 전환해야 하는 시점이라면
			if (dirChange.first == time)
			{
				// 방향 전환
				switch (dirChange.second)
				{
				case TURN_LEFT:
					snake.Direction = snake.Direction - 1 >= 0 ? snake.Direction - 1 : DIR_N;
					break;
				case TURN_RIGHT:
					snake.Direction = snake.Direction + 1 <= DIR_N ? snake.Direction + 1 : DIR_E;
					break;
				}

				// 큐에서 pop
				dirQ.pop();
			}
		}
	}

	return time;
}

int main()
{
	cin >> N >> K;

	gameMap.resize(N);
	for (int i = 0; i < N; ++i)
		gameMap[i].resize(N);

	for (int i = 0; i < K; ++i)
	{
		int row, col;
		cin >> row >> col;
		gameMap[row - 1][col - 1] = APPLE;
	}

	cin >> L;
	for (int i = 0; i < L; ++i)
	{
		int x;
		char c;
		cin >> x >> c;
		dirQ.push({ x, c });
	}

	cout << game();

	return 0;
}