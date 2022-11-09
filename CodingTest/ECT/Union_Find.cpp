#include <iostream>

using namespace std;

int v, e; // 노드와 간선 개수
int parentTable[100001]; // 부모 테이블

int findParent(int x)
{
	// 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
	// 호출 할때마다 부모 테이블 갱신한다 ( 경로 압축 )
	if (parentTable[x] != x)
		parentTable[x] = findParent(parentTable[x]);

	return parentTable[x];
}

void unionParent(int a, int b)
{
	int pA = findParent(a);
	int pB = findParent(b);

	if (pA < pB)
		parentTable[pB] = pA;
	else
		parentTable[pA] = pB;
}

int main()
{
	// 노드의 개수와 간선의 개수(union 연산의 개수) 입력받기
	cin >> v >> e;

	// 테이블 초기화
	memset(parentTable, 0, sizeof(int) * (v + 1));

	// 부모를 자기 자신으로 초기화
	for (int i = 1; i <= v; ++i)
		parentTable[i] = i;

	// union 연산 수행 
	int a, b;
	for (int i = 0; i < e; ++i)
	{
		cin >> a >> b;
		unionParent(a, b);
	}

	// 각 원소가 속한 집합 출력
	for (int i = 1; i <= v; ++i)
		cout << findParent(i) << " ";
	cout << "\n";

	// 부모 테이블 내용 출력
	for (int i = 1; i <= v; ++i)
		cout << parentTable[i] << " ";

	return 0;
}