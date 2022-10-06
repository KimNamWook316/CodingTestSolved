// https://school.programmers.co.kr/learn/courses/29/lessons/92341

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

struct ParkingData
{
    int recentTime;
    int acc;
    bool parked;

    ParkingData() :
        recentTime(0),
        acc(0),
        parked(false)
    {
    }
};

vector<int> solution(vector<int> fees, vector<string> records)
{
    int baseTime = fees[0];
    int baseFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];

    map<int, ParkingData> mapParkData;

    int hour, minute, plateNum;
    string buf;
    stringstream ss;

    for (int i = 0; i < records.size(); ++i)
    {
        ss << records[i];

        // Time
        getline(ss, buf, ':');
        hour = stoi(buf);

        ss >> minute;

        // ��ȣ�� ����
        ss >> plateNum;

        // ó�� �����ϴ� ������ Ȯ��
        auto find = mapParkData.find(plateNum);

        if (find == mapParkData.end())
        {
            ParkingData data;
            data.recentTime = hour * 60 + minute;
            data.parked = true;
            mapParkData.insert(make_pair(plateNum, data));
        }
        else
        {
            // ������ ���¿��� ������ ������ ���
            // ���� �ð� ����ϰ� outó��
            if (find->second.parked)
            {
                find->second.acc += (hour * 60 + minute) - find->second.recentTime;
                find->second.parked = false;
            }
            // �ٽ� �����Ϸ� ���� ���
            // �����Ϸ� ���� �ð� update
            else
            {
                find->second.recentTime = hour * 60 + minute;
                find->second.parked = true;
            }
        }

        ss.str("");
    }

    vector<int> answer;
    auto iter = mapParkData.begin();
    auto iterEnd = mapParkData.end();

    for (; iter != iterEnd; ++iter)
    {
        // ���� ���������� ��� 11:59 �������� ����
        if (iter->second.parked)
        {
            iter->second.acc += (23 * 60 + 59) - iter->second.recentTime;
        }

        int fee;

        if (iter->second.acc <= baseTime)
        {
            fee = baseFee;
        }
        else
        {
            fee = baseFee + ceil((float)(iter->second.acc - baseTime) / unitTime) * unitFee;
        }

        answer.push_back(fee);
    }

    return answer;
}