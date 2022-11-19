// ������ ���� �˰���
#include <iostream>

#define N 4 
#define R 3 

int nums[N + 1] = { 0, 1,2,3,4 };
bool check[N + 1] = { false, };
int ans[R] = { 0, };

void printAns()
{
	for (int i = 0; i < R; ++i)
		std::cout << ans[i] << " ";
	std::cout << std::endl;
}

// ����
void Permutation(int depth)
{
	if (depth == R)
	{
		printAns();
	}
	else
	{
		for (int i = 1; i <= N; ++i)
		{
			if (false == check[i])
			{
				check[i] = true;
				ans[depth] = nums[i];

				Permutation(depth + 1);

				check[i] = false;
			}
		}
	}
}

// �ߺ� ����
void PermutationOverlap(int depth)
{
	if (depth == R)
	{
		printAns();
	}
	else
	{
		for (int i = 1; i <= N; ++i)
		{
			ans[depth] = nums[i];
			PermutationOverlap(depth + 1);
		}
	}
}

// ����
void Combination(int depth, int next)
{
	if (depth == R)
	{
		printAns();
	}
	else
	{
		for (int i = next; i <= N; ++i)
		{
			ans[depth] = nums[i];
			Combination(depth + 1, i + 1);
		}
	}
}

// �ߺ� ����
void CombinationOverlap(int depth, int next)
{
	if (R == depth)
	{
		printAns();
	}
	else
	{
		for (int i = next; i <= N; ++i)
		{
			ans[depth] = nums[i];
			CombinationOverlap(depth + 1, i);
		}
	}
}