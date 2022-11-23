#include <iostream>

using namespace std;

struct Node
{
	Node() :
		left(nullptr),
		right(nullptr)
	{
	}

	char ch;
	Node* left;
	Node* right;
};

int n;
Node* nodes[26];

void preOrder(Node* node)
{
	cout << node->ch;

	if (node->left)
		preOrder(node->left);
	if (node->right)
		preOrder(node->right);
}

void inOrder(Node* node)
{
	if (node->left)
		inOrder(node->left);

	cout << node->ch;

	if (node->right)
		inOrder(node->right);
}

void postOrder(Node* node)
{
	if (node->left)
		postOrder(node->left);

	if (node->right)
		postOrder(node->right);

	cout << node->ch;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		nodes[i] = new Node;
		nodes[i]->ch = 'A' + i;
	}

	for (int i = 0; i < n; ++i)
	{
		char root, left, right;
		cin >> root >> left >> right;

		if ('.' != left)
			nodes[root - 'A']->left = nodes[left - 'A'];

		if ('.' != right)
			nodes[root - 'A']->right = nodes[right - 'A'];
	}

	preOrder(nodes[0]);
	cout << "\n";
	inOrder(nodes[0]);
	cout << "\n";
	postOrder(nodes[0]);
	cout << "\n";

	for (int i = 0; i < n; ++i)
		delete nodes[i];

	return 0;
}
