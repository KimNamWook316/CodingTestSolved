#include <iostream>
#include <vector>

using namespace std;

int* arr;
int cnt;
int ans = -1;

void merge(int* input, int p, int q, int r, int k)
{
    int i = p;
    int j = q + 1;
    int t = 0;

    vector<int> tmp(r - p + 1);
    while (i <= q && j <= r)
    {
        if (input[i] <= input[j])
            tmp[t++] = input[i++];
        else
            tmp[t++] = input[j++];
    }
    while (i <= q) tmp[t++] = input[i++];
    while (j <= r) tmp[t++] = input[j++];

    i = p; t = 0;
    while (i <= r)
    {
        input[i++] = tmp[t++];
        ++cnt;
        if (cnt == k)
            ans = input[i - 1];
    }
}

void merge_sort(int* input, int p, int r, int k)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(input, p, q, k);
        merge_sort(input, q + 1, r, k);
        merge(input, p, q, r, k);
    }
}

int main()
{
    int size, k;
    cin >> size >> k;

    arr = new int[size];

    for (int i = 0; i < size; ++i)
        cin >> arr[i];

    merge_sort(arr, 0, size - 1, k);
    cout << ans;

    delete[] arr;

    return 0;
}