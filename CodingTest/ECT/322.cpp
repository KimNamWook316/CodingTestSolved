// 유형별 기출문제 : 구현 >> p.322

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string input;
	cin >> input;

	string s;
	int sum = 0;
	for (int i = 0; i < input.length(); ++i)
	{
		if (input[i] >= '0' && input[i] <= '9')
			sum += input[i] - '0';
		else
			s += input[i];
	}

	sort(s.begin(), s.end());
	s += to_string(sum);

	cout << s;

	return 0;
}
