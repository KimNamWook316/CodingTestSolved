// https://school.programmers.co.kr/learn/courses/30/lessons/92335

#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

string ToNotation(int number, int notation)
{
    stack<int> stk;
    while (number >= 1)
    {
        stk.push(number % notation);
        number = number / notation;
    }

    string ret = "";
    while (!stk.empty())
    {
        ret += to_string(stk.top());
        stk.pop();
    }

    return ret;
}

bool IsPrime(long long num)
{
    if (num == 0 || num == 1)
        return false;

    for (long i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int solution(int n, int k)
{
    string num = ToNotation(n, k);

    stringstream ss(num);
    string buf;

    int answer = 0;

    while (getline(ss, buf, '0'))
    {
        if (buf.empty())
            continue;

        if (IsPrime(stoll(buf)))
            ++answer;
    }

    return answer;
}