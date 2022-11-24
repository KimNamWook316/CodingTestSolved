#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, ans = 0;
	priority_queue<int> q;

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		int input = 0;
		cin >> input;
		q.push(-input);
	}

	if (1 == n)
	{
		cout << 0;
		return 0;
	}

	while(q.size() > 1)
	{
		int deck1 = -q.top();
		q.pop();
		int deck2 = -q.top();
		q.pop();

		q.push(-(deck1 + deck2));
		ans += deck1 + deck2;
	}

	cout << ans;

	return 0;
}