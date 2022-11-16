#include <string>
#include <vector>

using namespace std;

int compLen(const string& s, int unit)
{
    // 압축 단위로 자른다
    vector<string> token;
    for (int i = 0; i < s.length(); i += unit)
        token.push_back(s.substr(i, unit));

    int ret = 0;
    string prev = token[0];
    int overlap = 0;
    
    // 겹치는 경우를 판별
    for (int i = 1; i < token.size(); ++i)
    {
        if (prev == token[i])
            ++overlap;

        // 이전 문자와 다른 경우
        else
        {
            // 중복이 있었을 경우 단위 + 나타난 숫자만큼 길이 +
            if (overlap > 0)
            {
                ret += unit + to_string(overlap + 1).length();
                overlap = 0;
            }
            // 중복이 없었을 경우 단위만큼만 길이 +
            else
            {
                ret += unit;
            }
            prev = token[i];
        }
    }

    // 남은 문자에 대한 처리
    if (overlap > 0)
        ret += unit + to_string(overlap + 1).length();
    else
        ret += token[token.size() - 1].size();

    return ret;
}

int solution(string s)
{
    int answer = 999999;

    // 1인 경우에 대한 처리
    if (s.length() == 1)
        return 1;

    // 압축 단위의 최대 == 문자열 길이의 반
    for (int i = 1; i <= s.length() / 2; ++i)
    {
        int afterComp = compLen(s, i);

        if (afterComp < answer)
            answer = afterComp;
    }

    return answer;
}