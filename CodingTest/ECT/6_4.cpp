// Sort >> p.182 두 배열의 원소 교체

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> A(n);
	vector<int> B(n);

	for (int i = 0; i < n; ++i) { cin >> A[i]; }
	for (int i = 0; i < n; ++i) { cin >> B[i]; }

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 0; i < k; ++i) { swap(A[i], B[i]); }

	int ans = accumulate(A.begin(), A.end(), 0);
	cout << ans;

	return 0;
}
