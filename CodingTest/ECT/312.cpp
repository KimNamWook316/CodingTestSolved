// 유형별 기출문제 : 그리디 알고리즘 >> p.312

#include <iostream>
#include <string>

using namespace std;

string input;
int nums[20];

int charToInt(char c)
{
	return c - '0';
}

int getMax()
{
	int ret = nums[0];
	for (int i = 1; i < input.size(); ++i)
	{
		if (1 >= nums[i - 1])
			ret += nums[i];
		else
			ret *= nums[i];
	}
	return ret;
}

int main()
{
	cin >> input;

	for (int i = 0; i < input.size(); ++i)
		nums[i] = charToInt(input[i]);

	cout << getMax();

	return 0;
}
