// https://school.programmers.co.kr/learn/courses/30/lessons/118667

#include <string>
#include <vector>
#include <numeric>

using namespace std;

typedef unsigned long long ULL;

int solution(vector<int> queue1, vector<int> queue2)
{
    ULL sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    ULL sum2 = accumulate(queue2.begin(), queue2.end(), 0);

    // 두 수의 합이 홀수인 경우
    if ((sum1 % 2 == 0 && sum2 % 2 == 1) || (sum1 % 2 == 1 && sum2 % 2 == 0))
        return -1;

    int idx1 = 0;
    int idx2 = 0;

    int size = queue1.size();

    int trialCount = 0;

    while (trialCount < size * 2 + size)
    {
        if (sum1 == sum2)
        {
            return trialCount;
        }

        if (sum1 > sum2)
        {
            int pop = queue1[idx1++];
            sum1 -= pop;
            sum2 += pop;

            queue2.push_back(pop);
        }
        else
        {
            int pop = queue2[idx2++];
            sum1 += pop;
            sum2 -= pop;

            queue1.push_back(pop);
        }

        ++trialCount;
    }

    return -1;
}