#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int cnt;

int recursion(const char* s, int l, int r) {
    ++cnt;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main()
{
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; ++i)
        cin >> strings[i];

    int rec;
    for (int i = 0; i < n; ++i)
    {
        rec = isPalindrome(strings[i].c_str());
        cout << rec << " " << cnt << '\n';
        cnt = 0;
    }

    return 0;
}