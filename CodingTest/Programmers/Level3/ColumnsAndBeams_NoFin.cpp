#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int   DESTRUCT = 0;
constexpr int   CONSTRUCT = 1;

// 기둥, 보 설치 여부
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

    // 보가 설치되어 있는 경우
    if (info[y][x].second)
        return true;

    if (x - 1 > 0)
    {
        if (info[y][x - 1].second)
            return true;
    }

    // 아래 기둥이 있는 경우
    if (info[y - 1][x].first)
        return true;

    return false;
}

bool isValidBeam(int x, int y)
{
    if (!isValidIndex(x, y))
        return false;

    // 바로 아래 기둥이 있는 경우
    if (y - 1 >= 0)
    {
        if (info[y - 1][x].first)
            return true;

        // 오른쪽 아래 기둥이 있는 경우
        if (x + 1 < info.size())
        {
            if (info[y - 1][x + 1].first)
                return true;
        }
    }

    // 양쪽 끝이 다른 보에 연결되는 경우
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

    // 설치 정보만 담고 있는 배열
    info.resize(n + 1);

    // 설치 벽면 정보 초기화
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

        // 삭제
        if (0 == b)
        {
            // 기둥
            if (0 == a)
            {
                // 바로 위에 기둥이 있는 경우
				// 좌상단 보나 우상단 보가 없다면 존재할 수 없다.
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

					// 우상단 보 존재하는 경우
                    if (info[y + 1][x].second)
                    {
                        bool valid = false;

                        // 삭제할 기둥 오른쪽에 또 기둥이 있거나
                        if (isValidIndex(x + 1, y))
                        {
                            if (info[y][x + 1].first)
                                valid = true;
                        }

                        // 왼쪽 오른쪽에 보가 존재하는 경우가 아니면 존재할 수 없다.
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

                // 좌상단 보 존재하는 경우
                if (isValidIndex(x - 1, y + 1))
                {
                    if (info[y + 1][x - 1].second)
                    {
                        bool valid = false;
                        // 삭제할 기둥 왼쪽에 기둥이 있거나
                        if (isValidIndex(x - 1, y))
                        {
                            valid = info[y][x - 1].first;
                        }

                        // 왼쪽 오른쪽에 보가 존재하거나
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

                // 주변 기물이 영향을 받지 않는 경우 삭제한다.
                info[y][x].first = false;
            }
            // 보
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

                // 왼쪽 기둥이 존재하는 경우
                if (leftPillar)
                {
                    bool valid = false;

                    // 바로 아래 기둥이 존재하거나
                    if (isValidIndex(x, y - 1))
                    {
                        valid = info[y - 1][x].first;
                    }

                    // 왼쪽 보가 존재하는 경우
                    if (!valid)
						valid = leftBeam;

                    if (!valid)
                        continue;
                }

                // 오른쪽 기둥이 존재하는 경우
                if (rightPillar)
                {
                    bool valid = false;

                    // 바로 아래 기둥이 존재하거나
					if (isValidIndex(x + 1, y - 1))
					{
                        valid = info[y - 1][x + 1].first;
					}

                    // 오른쪽 보가 존재하는 경우
                    if (!valid)
						valid = rightBeam;

                    if (!valid)
                        continue;
                }

                // 왼쪽 보가 존재하는 경우
                if (leftBeam)
                {
                    bool valid = false;

                    // 왼쪽 아래 기둥이 존재하는 경우
                    if (isValidIndex(x - 1, y - 1))
                    {
                        valid = info[y - 1][x - 1].first;
                    }

                    // 왼쪽 보 기준 오른쪽 기둥이 존재하는 경우
                    if (!valid)
						valid = leftPillar;

                    if (!valid)
                        continue;
                }

                // 오른쪽 보가 존재하는 경우
                if (rightBeam)
                {
                    bool valid = false;

                    // 오른쪽 보 기준 왼쪽 기둥이 존재하는 경우
                    if (isValidIndex(x + 1, y - 1))
                        valid = info[y - 1][x + 1].first;

                    // 오른쪽 보 기준 오른쪽 기둥이 존재하는 경우
                    if (isValidIndex(x + 2, y - 1))
                        valid = info[y - 1][x + 1].first;

                    if (!valid)
                        continue;
                }

                // 주변 기물이 영향을 받지 않는 경우 삭제
                info[y][x].second = false;
            }
        }
        // 설치
        else
        {
            // 기둥 설치
            if (0 == a)
            {
                if (isValidPillar(x, y))
                    info[y][x].first = true;
            }
            // 보 설치
            else
            {
                if (isValidBeam(x, y))
                    info[y][x].second = true;
            }
        }
    }

    // 설치 지점 저장 배열에서 설치 정보를 추려낸다.
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
