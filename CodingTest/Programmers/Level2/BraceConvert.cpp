#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void reverse(string& str)
{
    for (int i = 0; i < str.length(); ++i)
    {
        if ('(' == str[i])
        {
            str[i] = ')';
        }
        else if (')' == str[i])
        {
            str[i] = '(';
        }
    }
}

bool isCorrect(const string& str)
{
    stack<char> stk;

    for (const char& c : str)
    {
        if ('(' == c)
        {
            stk.push(c);
        }
        if (')' == c)
        {
            if (stk.empty())
                return false;
            else
            {
                stk.pop();
            }
        }
    }

    return stk.empty();
}

bool isBalanced(const string& str)
{
    string u, v;
    int lC = 0;
    int rC = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        if ('(' == str[i])
            ++lC;
        if (')' == str[i])
            ++rC;
    }

    return lC == rC;
}

pair<string, string> splitUV(const string& str)
{
    string u, v;
    int lC = 0;
    int rC = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        if ('(' == str[i])
            ++lC;
        if (')' == str[i])
            ++rC;

        if (lC == rC)
        {
            u = str.substr(0, i + 1);
            v = str.substr(i + 1, string::npos);
            return { u, v };
        }
    }

    return { u, v };
}

string step(const string& str)
{
    if (str.empty())
        return str;

    pair<string, string> uv = splitUV(str);

    if (isCorrect(uv.first))
    {
        return uv.first + step(uv.second);
    }
    else
    {
        string empty("(");
    	empty += step(uv.second);
        empty += ")";

        string uCutOff;
        for (int i = 1; i < uv.first.length() - 1; ++i)
            uCutOff += uv.first[i];

        reverse(uCutOff);
        empty += uCutOff;

        return empty;
    }
}

string solution(string p)
{
    string answer = p;

    if (p.length() == 0)
        return p;

    while (false == isCorrect(answer))
    {
        answer = step(p);
    }

    return answer;
}

int main()
{
    string input = "()))((()";

    string ans = solution(input);

    cout << ans;

    return 0;
}