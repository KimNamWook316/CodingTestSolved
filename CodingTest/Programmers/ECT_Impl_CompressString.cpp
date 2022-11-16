#include <string>
#include <vector>

using namespace std;

int compLen(const string& s, int unit)
{
    // ���� ������ �ڸ���
    vector<string> token;
    for (int i = 0; i < s.length(); i += unit)
        token.push_back(s.substr(i, unit));

    int ret = 0;
    string prev = token[0];
    int overlap = 0;
    
    // ��ġ�� ��츦 �Ǻ�
    for (int i = 1; i < token.size(); ++i)
    {
        if (prev == token[i])
            ++overlap;

        // ���� ���ڿ� �ٸ� ���
        else
        {
            // �ߺ��� �־��� ��� ���� + ��Ÿ�� ���ڸ�ŭ ���� +
            if (overlap > 0)
            {
                ret += unit + to_string(overlap + 1).length();
                overlap = 0;
            }
            // �ߺ��� ������ ��� ������ŭ�� ���� +
            else
            {
                ret += unit;
            }
            prev = token[i];
        }
    }

    // ���� ���ڿ� ���� ó��
    if (overlap > 0)
        ret += unit + to_string(overlap + 1).length();
    else
        ret += token[token.size() - 1].size();

    return ret;
}

int solution(string s)
{
    int answer = 999999;

    // 1�� ��쿡 ���� ó��
    if (s.length() == 1)
        return 1;

    // ���� ������ �ִ� == ���ڿ� ������ ��
    for (int i = 1; i <= s.length() / 2; ++i)
    {
        int afterComp = compLen(s, i);

        if (afterComp < answer)
            answer = afterComp;
    }

    return answer;
}