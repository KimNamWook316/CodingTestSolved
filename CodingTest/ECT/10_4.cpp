// 그래프 이론 >> p.303 커리큘럼
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int inDegree[501];
	int cost[501];
	vector<int> link[501];
	int result[501];

	// 강의 개수
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		inDegree[i] = 0;
		cost[i] = 0;
	}

	int time, pre;
	for (int i = 1; i <= n ; ++i)
	{
		cin >> time;
		cost[i] = time;

		cin >> pre;
		while (pre != -1)
		{
			++inDegree[i];
			link[pre].push_back(i);
			cin >> pre;
		}
	}

	int degZero = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (inDegree[i] == 0)
		{
			degZero = i;
			break;
		}
	}

	queue<int> q;
	q.push(degZero);

	memcpy(result, cost, sizeof(int) * 501);

	// Topology Sort
	while(!q.empty())
	{
		const int idx = q.front();
		q.pop();

		// 차수 빼주고, 해당 노드까지 도착하기까지 걸리는 시간을 계산한다.
		for (int i = 0; i < link[idx].size(); ++i)
		{
			result[link[idx][i]] = max(result[link[idx][i]], result[idx] + cost[link[idx][i]]);
			--inDegree[link[idx][i]];

			if (0 == inDegree[link[idx][i]])
				q.push(link[idx][i]);
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << result[i] << endl;

	return 0;
}
