#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(int i)
{
    cout << i << "\n";
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    // O(nlogn) ∫∏¿Â
    sort(nums.begin(), nums.end());
    for_each(nums.begin(), nums.end(), print_vec);

    return 0;
}