// Binary Search >> p.197 ��ǰ ã��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� Ž��
bool isExist(int find, const vector<int>& vec)
{
	int start = 0;
	int end = vec.size() - 1;

	while (start <= end)
	{
		int middle = (start + end) / 2;

		if (vec[middle] == find)
		{
			return true;
		}
		else if (vec[middle] < find)
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}

	return false;
}

int main()
{
	int n, m;
	vector<int> stock, recommend;

	cin >> n;
	stock.resize(n);
	for (int i = 0; i < n; ++i) { cin >> stock[i]; }

	cin >> m;
	recommend.resize(m);
	for (int i = 0; i < m; ++i) { cin >> recommend[i]; }

	// ��� �������� ����
	sort(stock.begin(), stock.end());

	for (int i = 0; i < m; ++i)
	{
		if (isExist(recommend[i], stock))
			cout << "yes ";
		else
			cout << "no ";
	}

	return 0;
}
