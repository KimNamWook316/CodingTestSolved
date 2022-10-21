#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10001] = {};

int main()
{
    int n, input;
    scanf_s("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf_s("%d", &input);
        ++arr[input];
    }

    for (int i = 0; i <= 10000; ++i)
    {
        if (arr[i] != 0)
        {
			for (int j = 0; j < arr[i]; ++j)
			{
                printf("%d\n", i);
			}
        }
    }

    return 0;
}