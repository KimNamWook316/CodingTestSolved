#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int len = 0;
    cin >> len;

    vector<int> nums(len);

    for (int i = 0; i < len; ++i)
    {
        cin >> nums[i];
    }

    for (size_t i = 0; i < nums.size(); ++i)
    {
        for (size_t j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] > nums[j])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    for (size_t i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << "\n";
    }

    return 0;
}