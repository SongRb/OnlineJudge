#include<iostream>
#include<cstdio>
using namespace std;

void postOrder(int* inOrder, int* preOrder, int length)
{
	if (length == 0)
	{
		return;
	}
	int elem = preOrder[0];
	int rootIndex = 0;

	for (; rootIndex < length; rootIndex++)
	{
		if (inOrder[rootIndex] == preOrder[0])
			break;
	}
	postOrder(inOrder, preOrder + 1, rootIndex);
	postOrder(inOrder + rootIndex + 1, preOrder + rootIndex + 1, length - (rootIndex + 1));

	printf("%d ", elem);
}

int preOrderTree[100000];
int inOrderTree[100000];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &preOrderTree[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &inOrderTree[i]);
	}
	postOrder(inOrderTree, preOrderTree, N);
	return 0;
}