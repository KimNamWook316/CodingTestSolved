#include <iostream>

using namespace std;

int solve(int n) 
{
    if (n < 3)
        return -1;

    int table[5001] = {};
    table[3] = 1;
    table[5] = 1;

    for (int i = 6; i <= n; ++i) 
    {
        if (table[i - 5] > 0 && table[i - 3] > 0)
            table[i] = min(table[i - 5] + 1, table[i - 3] + 1);
        else if (table[i - 5] > 0)
            table[i] = table[i - 5] + 1;
        else if (table[i - 3] > 0)
            table[i] = table[i - 3] + 1;
    }

    if (table[n] == 0)
        return -1;
    else
        return table[n];
}

int main() 
{
    int n;
    cin >> n;

    cout << solve(n);
    return 0;
}