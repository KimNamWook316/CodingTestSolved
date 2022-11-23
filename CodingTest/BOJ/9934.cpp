#include <iostream>
#include <vector>

using namespace std;

int k;
int inOrder[1025];
vector<int> tree[1025];

void divide(int start, int end, int height)
{
	if (start > end)
		return;

	if (height > k)
		return;

	int mid = (start + end) / 2;
	tree[height].push_back(inOrder[mid]);

	divide(start, mid - 1, height + 1);
	divide(mid + 1, end, height + 1);
}

int main()
{
	cin >> k;

	for (int i = 1; i < pow(2, k); ++i)
		cin >> inOrder[i];

	divide(1, pow(2, k) - 1, 1);

	for (int i = 1; i <= k; ++i)
	{
		for (int j = 0; j < tree[i].size(); ++j)
		{
			cout << tree[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}