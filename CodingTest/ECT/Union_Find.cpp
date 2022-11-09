#include <iostream>

using namespace std;

int v, e; // ���� ���� ����
int parentTable[100001]; // �θ� ���̺�

int findParent(int x)
{
	// ��Ʈ ��尡 �ƴ϶��, ��Ʈ ��带 ã�� ������ ��������� ȣ��
	// ȣ�� �Ҷ����� �θ� ���̺� �����Ѵ� ( ��� ���� )
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
	// ����� ������ ������ ����(union ������ ����) �Է¹ޱ�
	cin >> v >> e;

	// ���̺� �ʱ�ȭ
	memset(parentTable, 0, sizeof(int) * (v + 1));

	// �θ� �ڱ� �ڽ����� �ʱ�ȭ
	for (int i = 1; i <= v; ++i)
		parentTable[i] = i;

	// union ���� ���� 
	int a, b;
	for (int i = 0; i < e; ++i)
	{
		cin >> a >> b;
		unionParent(a, b);
	}

	// �� ���Ұ� ���� ���� ���
	for (int i = 1; i <= v; ++i)
		cout << findParent(i) << " ";
	cout << "\n";

	// �θ� ���̺� ���� ���
	for (int i = 1; i <= v; ++i)
		cout << parentTable[i] << " ";

	return 0;
}