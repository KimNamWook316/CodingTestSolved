// 그리디 알고리즘 >> p.96 숫자 카드 게임 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	// 첫 작성 답안
	{
 //		int n, m, input, ans = 0;
 //		cin >> n >> m;
 //
 //		vector<vector<int>> cards(n);
 //		for (int i = 0; i < n; ++i)
 //		{
 //			for (int j = 0; j < m; ++j)
 //			{
 //				cin >> input;
 //				cards[i].push_back(input);
 //			}
 //		}

 //		// 최소값이 가장 큰 행을 찾는다.
 //		for (int i = 0; i < n; ++i)
 //		{
 //			sort(cards[i].begin(), cards[i].end());
 //		}
 //
 //		// 각 행의 최소값을 비교한다. 
 //		for (int i = 0; i < n; ++i)
 //		{
 //			if (cards[i][0] > ans)
 //				ans = cards[i][0];
 //		}
 //
 //		cout << ans;
	}

	// 개선안
	{
		int n, m, input;
		cin >> n >> m;

		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			// 한 줄씩 입력 받아서 행의 가장 작은 수 찾는다.
			int minVal = 10001;
			for (int j = 0; j < m; ++j)
			{
				cin >> input;
				minVal = min(minVal, input);
			}

			// 행의 최소값들을 비교해 가장 큰 수를 찾는다.
			ans = max(ans, minVal);
		}

		cout << ans;
	}

	return 0;
}