#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int   DESTRUCT = 0;
constexpr int   CONSTRUCT = 1;

// ���, �� ��ġ ����
vector<vector<pair<bool, bool>>> info;

bool isValidIndex(int x, int y)
{
    if (x < 0 || y < 0 || x >= info.size() || y >= info.size())
        return false;

    return true;
}

bool isValidPillar(int x, int y)
{
    if (!isValidIndex(x, y))
        return false;

    if (0 == y)
        return true;

    // ���� ��ġ�Ǿ� �ִ� ���
    if (info[y][x].second)
        return true;

    if (x - 1 > 0)
    {
        if (info[y][x - 1].second)
            return true;
    }

    // �Ʒ� ����� �ִ� ���
    if (info[y - 1][x].first)
        return true;

    return false;
}

bool isValidBeam(int x, int y)
{
    if (!isValidIndex(x, y))
        return false;

    // �ٷ� �Ʒ� ����� �ִ� ���
    if (y - 1 >= 0)
    {
        if (info[y - 1][x].first)
            return true;

        // ������ �Ʒ� ����� �ִ� ���
        if (x + 1 < info.size())
        {
            if (info[y - 1][x + 1].first)
                return true;
        }
    }

    // ���� ���� �ٸ� ���� ����Ǵ� ���
    if (x - 1 >= 0 && x + 1 < info.size())
    {
        if (info[y][x - 1].second && info[y][x + 1].second)
            return true;
    }

    return false;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;

    // ��ġ ������ ��� �ִ� �迭
    info.resize(n + 1);

    // ��ġ ���� ���� �ʱ�ȭ
    for (int i = 0; i <= n; ++i)
    {
        info[i].resize(n + 1);
        for (int j = 0; j <= n; ++j)
        {
            info[i][j].first = false;
            info[i][j].second = false;
        }
    }

    for (int i = 0; i < build_frame.size(); ++i)
    {
        int x, y, a, b;
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];

        // ����
        if (0 == b)
        {
            // ���
            if (0 == a)
            {
                // �ٷ� ���� ����� �ִ� ���
				// �»�� ���� ���� ���� ���ٸ� ������ �� ����.
                if (isValidIndex(x, y + 1))
                {
                    if (info[y + 1][x].first)
                    {
                        bool leftBeam = false;
                        bool rightBeam = false;
                        if (isValidIndex(y + 1, x - 1))
                        {
                            if (info[y + 1][x - 1].second)
                            {
                                leftBeam = true;
                            }
                        }

                        if (info[y + 1][x].second)
                            rightBeam = true;

                        if (!leftBeam || !rightBeam)
                            continue;
                    }

					// ���� �� �����ϴ� ���
                    if (info[y + 1][x].second)
                    {
                        bool valid = false;

                        // ������ ��� �����ʿ� �� ����� �ְų�
                        if (isValidIndex(x + 1, y))
                        {
                            if (info[y][x + 1].first)
                                valid = true;
                        }

                        // ���� �����ʿ� ���� �����ϴ� ��찡 �ƴϸ� ������ �� ����.
                        bool leftBeam = false;
                        bool rightBeam = false;

                        if (isValidIndex(x - 1, y + 1))
                            leftBeam = info[y + 1][x - 1].second;

                        if (isValidIndex(x + 1, y + 1))
                            rightBeam = info[y + 1][x + 1].second;

                        if (!leftBeam || !rightBeam)
                            valid = false;
                        else
                            valid = true;

                        if (!valid)
                            continue;
                    }
                }

                // �»�� �� �����ϴ� ���
                if (isValidIndex(x - 1, y + 1))
                {
                    if (info[y + 1][x - 1].second)
                    {
                        bool valid = false;
                        // ������ ��� ���ʿ� ����� �ְų�
                        if (isValidIndex(x - 1, y))
                        {
                            valid = info[y][x - 1].first;
                        }

                        // ���� �����ʿ� ���� �����ϰų�
                        bool leftBeam = false;
                        bool rightBeam = false;

                        if (isValidIndex(x - 2, y + 1))
                        {
                            leftBeam = info[y + 1][x - 2].second;
                        }

                        if (isValidIndex(x , y + 1))
                        {
							rightBeam = info[y + 1][x].second;
                        }

                        if (!leftBeam || !rightBeam)
                        {
                            valid = false;
                        }
                        else
                        {
                            valid = true;
                        }

                        if (!valid)
                            continue;
                    }
                }

                // �ֺ� �⹰�� ������ ���� �ʴ� ��� �����Ѵ�.
                info[y][x].first = false;
            }
            // ��
            else
            {
                bool leftPillar = info[y][x].first;
                bool rightPillar = false;
                bool leftBeam = false;
                bool rightBeam = false;

                if (isValidIndex(x - 1, y))
                    leftBeam = info[y][x - 1].second;

                if (isValidIndex(x + 1, y))
                {
                    rightPillar = info[y][x + 1].first;
                    rightBeam = info[y][x + 1].second;
                }

                // ���� ����� �����ϴ� ���
                if (leftPillar)
                {
                    bool valid = false;

                    // �ٷ� �Ʒ� ����� �����ϰų�
                    if (isValidIndex(x, y - 1))
                    {
                        valid = info[y - 1][x].first;
                    }

                    // ���� ���� �����ϴ� ���
                    if (!valid)
						valid = leftBeam;

                    if (!valid)
                        continue;
                }

                // ������ ����� �����ϴ� ���
                if (rightPillar)
                {
                    bool valid = false;

                    // �ٷ� �Ʒ� ����� �����ϰų�
					if (isValidIndex(x + 1, y - 1))
					{
                        valid = info[y - 1][x + 1].first;
					}

                    // ������ ���� �����ϴ� ���
                    if (!valid)
						valid = rightBeam;

                    if (!valid)
                        continue;
                }

                // ���� ���� �����ϴ� ���
                if (leftBeam)
                {
                    bool valid = false;

                    // ���� �Ʒ� ����� �����ϴ� ���
                    if (isValidIndex(x - 1, y - 1))
                    {
                        valid = info[y - 1][x - 1].first;
                    }

                    // ���� �� ���� ������ ����� �����ϴ� ���
                    if (!valid)
						valid = leftPillar;

                    if (!valid)
                        continue;
                }

                // ������ ���� �����ϴ� ���
                if (rightBeam)
                {
                    bool valid = false;

                    // ������ �� ���� ���� ����� �����ϴ� ���
                    if (isValidIndex(x + 1, y - 1))
                        valid = info[y - 1][x + 1].first;

                    // ������ �� ���� ������ ����� �����ϴ� ���
                    if (isValidIndex(x + 2, y - 1))
                        valid = info[y - 1][x + 1].first;

                    if (!valid)
                        continue;
                }

                // �ֺ� �⹰�� ������ ���� �ʴ� ��� ����
                info[y][x].second = false;
            }
        }
        // ��ġ
        else
        {
            // ��� ��ġ
            if (0 == a)
            {
                if (isValidPillar(x, y))
                    info[y][x].first = true;
            }
            // �� ��ġ
            else
            {
                if (isValidBeam(x, y))
                    info[y][x].second = true;
            }
        }
    }

    // ��ġ ���� ���� �迭���� ��ġ ������ �߷�����.
    for (int i = 0; i < info.size(); ++i)
    {
        for (int j = 0; j < info.size(); ++j)
        {
            if (info[i][j].first)
            {
                answer.push_back({ j, i, 0 });
            }
            if (info[i][j].second)
            {
                answer.push_back({ j, i, 1 });
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<vector<int>> buildFrame =
    {
 //         {1,0,0,1} ,{1,1,1,1},{2,1,0,1},{2,2,1,1},
 //         {5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1}
  	    {0,0,0,1},
      	{2,0,0,1},
      	{4,0,0,1},
      	{0,1,1,1},
      	{1,1,1,1},
      	{2,1,1,1},
  		{3,1,1,1},
      	{2,0,0,0},
      	{1,1,1,0},
      	{2,2,0,1}
    };

    vector<vector<int>> ans = solution(5, buildFrame);

    return 0;
}
