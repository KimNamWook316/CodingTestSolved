#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool IsGroup(const string& str)
{
    set<char> setChar;

    char prev = '#';
    for (int i = 0; i < str.length(); ++i)
    {
        auto find = setChar.find(str[i]);

        if (find == setChar.end())
        {
            setChar.insert(str[i]);
        }
        else
        {
            if (prev != str[i])
                return false;
        }

        prev = str[i];
    }

    return true;
}

int main()
{
    int num = 0;
    string input;
    int answer = 0;

    cin >> num;

    for (int i = 0; i < num; ++i)
    {
        cin >> input;

        if (IsGroup(input))
            ++answer;
    }

    cout << answer;

    return 0;
}