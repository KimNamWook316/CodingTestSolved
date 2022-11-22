#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int inDegree[32001];
vector<vector<int>> link;

void topologySort()
{
	priority_queue<int> q;

	for (int i = 1; i <= n; ++i)
	{
		if(inDegree[i] == 0)
		{
			q.push(i);
		}
	}

	while(!q.empty())
	{
		int idx = q.top();
		q.pop();

		cout << idx << " ";

		for (int i = 0; i < link[idx].size(); ++i)
		{
			int linkIdx = link[idx][i];
			--inDegree[linkIdx];

			if (inDegree[linkIdx] == 0)
				q.push(linkIdx);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	link.resize(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int front, back;
		cin >> front >> back;

		link[front].emplace_back(back);
		++inDegree[back];
	}

	topologySort();

	return 0;
}
