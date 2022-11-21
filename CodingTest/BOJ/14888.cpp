#include <iostream>
#include <vector>

using namespace std;

#define PLUS 0
#define MINUS 1
#define MULTIPLY 2
#define DIVIDE 3

// 입력받을 변수
int n;
int nums[11];
int ops[10];

// 경우의 수 체크를 위한 변수
bool check[10];

// 경우의 수 임시 변수
int opCase[10];

// 연산자 배치 경우의 수가 저장될 벡터
vector<vector<int>> opCases;

void permutation(int depth)
{
	if (depth == n - 1)
	{
		vector<int> temp(n-1);
		for (int i = 0; i < n - 1; ++i)
			temp[i] = opCase[i];

		opCases.emplace_back(temp);
	}
	else
	{
		for (int i = 0; i < n - 1; ++i)
		{
			if (!check[i])
			{
				check[i] = true;

				opCase[depth] = i;
				permutation(depth + 1);

				check[i] = false;
			}
		}
	}
}

int main()
{
	// 입력
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	int numOps[4];
	for (int i = 0; i < 4; ++i)
		cin >> numOps[i];

	int count = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < numOps[i]; ++j)
		{
			ops[count] = i;
			++count;
		}
	}
	//

	// 모든 연산자 배치 경우의 수를 구한다.
	permutation(0);

	// 최소, 최댓값 구한다.
	int minVal = 2e9;
	int maxVal = -2e9;

	for (const auto& opc : opCases)
	{
		int sum = nums[0];

		for (int i = 0; i < n - 1; ++i)
		{
			switch (ops[opc[i]])
			{
			case PLUS:
				sum += nums[i + 1];
				break;
			case MINUS:
				sum -= nums[i + 1];
				break;
			case MULTIPLY:
				sum *= nums[i + 1];
				break;
			case DIVIDE:
				sum /= nums[i + 1];
				break;
			}
		}

		minVal = min(minVal, sum);
		maxVal = max(maxVal, sum);
	}

	cout << maxVal << "\n" << minVal << "\n";

	return 0;
}