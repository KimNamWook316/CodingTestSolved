// �׸��� �˰��� >> p.96 ���� ī�� ���� 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	// ù �ۼ� ���
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

 //		// �ּҰ��� ���� ū ���� ã�´�.
 //		for (int i = 0; i < n; ++i)
 //		{
 //			sort(cards[i].begin(), cards[i].end());
 //		}
 //
 //		// �� ���� �ּҰ��� ���Ѵ�. 
 //		for (int i = 0; i < n; ++i)
 //		{
 //			if (cards[i][0] > ans)
 //				ans = cards[i][0];
 //		}
 //
 //		cout << ans;
	}

	// ������
	{
		int n, m, input;
		cin >> n >> m;

		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			// �� �پ� �Է� �޾Ƽ� ���� ���� ���� �� ã�´�.
			int minVal = 10001;
			for (int j = 0; j < m; ++j)
			{
				cin >> input;
				minVal = min(minVal, input);
			}

			// ���� �ּҰ����� ���� ���� ū ���� ã�´�.
			ans = max(ans, minVal);
		}

		cout << ans;
	}

	return 0;
}