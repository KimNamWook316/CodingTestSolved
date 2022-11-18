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

		// ���� �Ӹ��� ��ġ
		pair<int, int> head = snake.Body.front();

		// �Ӹ��� ��ġ�� �����������
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

		// ���� ���� ��� ����
		if (head.first < 0 ||
			head.first >= N ||
			head.second < 0 ||
			head.second >= N)
			break;

		// ���� ���⿡ ���� ������ ����
		if (gameMap[head.first][head.second] == BODY)
			break;

		// �Ӹ� �̵�
		snake.Body.push_front({ head.first, head.second });

		// ����� ���� ��� ���� ����
		if (gameMap[head.first][head.second] != APPLE)
		{
			// �ʿ� ���
			pair<int, int> tail = snake.Body.back();

			// �ʿ� ���
			gameMap[tail.first][tail.second] = VOID;

			// ���� ����
			snake.Body.pop_back();
		}

		// �ʿ� ���
		gameMap[head.first][head.second] = BODY;

		// ���� ��ȯ�ؾ� �ϴ��� ���
		if (!dirQ.empty())
		{
			pair<int, char> dirChange = dirQ.front();

			// ���� ��ȯ�ؾ� �ϴ� �����̶��
			if (dirChange.first == time)
			{
				// ���� ��ȯ
				switch (dirChange.second)
				{
				case TURN_LEFT:
					snake.Direction = snake.Direction - 1 >= 0 ? snake.Direction - 1 : DIR_N;
					break;
				case TURN_RIGHT:
					snake.Direction = snake.Direction + 1 <= DIR_N ? snake.Direction + 1 : DIR_E;
					break;
				}

				// ť���� pop
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