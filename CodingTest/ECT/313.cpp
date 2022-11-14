// 유형별 기출문제 : 그리디 알고리즘 >> p.313
#include <iostream>
#include <string>

using namespace std;

int getReverseCount(const string& input)
{
	int serialZero = 0;
	int serialOne = 0;

	char prev = input[0];
	for (int i = 1; i < input.length(); ++i)
	{
		if (prev != input[i])
		{
			if (prev == '0')
				++serialZero;
			else
				++serialOne;
		}
		prev = input[i];
	}
	return min(serialOne, serialZero);
}

int main()
{
	string input;
	cin >> input;

	cout << getReverseCount(input);

	return 0;
}
