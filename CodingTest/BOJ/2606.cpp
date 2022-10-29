#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
bool check[101];
vector<int> links[101];

void dfs(int idx)
{
	check[idx] = true;

	for (int i = 0; i < links[idx].size(); ++i)
	{
		if (!check[links[idx][i]])
		{
			++answer;
			dfs(links[idx][i]);
		}
	}
}

int main()
{
	int comCount, linkCnt;
	cin >> comCount >> linkCnt;

	int comIdx, linkIdx;
	for (int i = 0; i < linkCnt; ++i)
	{
		cin >> comIdx >> linkIdx;
		links[comIdx].push_back(linkIdx);
		links[linkIdx].push_back(comIdx);
	}

	dfs(1);

	cout << answer;

	return 0;
}
