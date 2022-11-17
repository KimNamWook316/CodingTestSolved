#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
int kSz = 0;
int lSz = 0;
int bSz = 0;

void turn(vector<vector<int>>& key)
{
    vector<vector<int>> temp(key.size());

    for (int i = 0; i < key.size(); ++i)
    {
        temp[i].resize(key[i].size());

        for (int j = 0; j < key[i].size(); ++j)
        {
            temp[i][j] = key[key.size() - 1 - j][i];
        }
    }

    key = temp;
}

bool match(const vector<vector<int>>& key, int offsetI, int offsetJ)
{
    bool ret = true;

    // board에 key를 맞춤
    for (int i = 0; i < kSz; ++i)
    {
        for (int j = 0; j < kSz; ++j)
        {
            board[i + offsetI][j + offsetJ] += key[i][j];
        }
    }

    // lock 범위를 확인
    for (int i = 0; i < lSz; ++i)
    {
        for (int j = 0; j < lSz; ++j)
        {
            int idxI = kSz - 1 + i;
            int idxJ = kSz - 1 + j;

            if (board[idxI][idxJ] == 0 || board[idxI][idxJ] == 2)
            {
                ret = false;
                break;
            }
        }

        if (!ret)
            break;
    }

    // 자물쇠가 맞으면 리턴, 아니면 board이전 상태로 되돌림
    if (ret)
        return true;
    else
    {
        for (int i = 0; i < kSz; ++i)
        {
            for (int j = 0; j < kSz; ++j)
            {
                board[i + offsetI][j + offsetJ] -= key[i][j];
            }
        }
        return false;
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    kSz = key.size();
    lSz = lock.size();
    bSz = lSz * 2 + kSz - 2;

    // 보드 초기화
    board.resize(bSz);
    for (int i = 0; i < board.size(); ++i)
        board[i].resize(bSz);

    // 보드 중앙에 자물쇠 배치
    for (int i = 0; i < lSz; ++i)
    {
        for (int j = 0; j < lSz; ++j)
        {
            board[kSz - 1 + i][kSz - 1 + j] = lock[i][j];
        }
    }

    // 오른쪽 아래 한 칸 겹치는 범위부터 왼쪽 위 한 칸 겹치는 범위까지 완전 탐색
    for (int i = 0; i <= bSz - kSz - 1; ++i)
    {
        for (int j = 0; j <= bSz - kSz - 1; ++j)
        {
            // key 돌리면서 확인
            for (int k = 0; k < 4; ++k)
            {
                if (match(key, i, j))
                    return true;
                else
                    turn(key);
            }
        }
    }

    return false;
}

void main()
{
 //    vector<vector<int>> key = { {0,0,0}, {1,0,0}, {0,1,1} };
 //    vector<vector<int>> lock = { {1,1,1}, {1,1,0}, {1,0,1} };
    vector<vector<int>> key = { {1,0,0}, {1,0,0}, {1,0,0} };
    vector<vector<int>> lock = { {0,0,0}, {0,0,0}, {0,0,0} };
    bool ret = solution(key, lock);
    cout << ret;
}