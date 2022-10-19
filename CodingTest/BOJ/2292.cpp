#include <iostream>
#include <cmath>

int GetSum(int k)
{
    return 1 + 6 * ((2 + (k - 1)) * k / (float)2);
}

int main()
{
    int i;
    std::cin >> i;

    int sum = 0;
    int cnt = 0;
    do 
    {
        sum = GetSum(cnt);
        ++cnt;
    } while (sum < i);

    std::cout << cnt;

    return 0;
}