#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Range
{
	int left, right;
};

Range tt[100];
bool tree[10005];

int main()
{
	memset(tree, true, sizeof(tree));

	int L, M;
	int top = -1;
	scanf("%d%d", &L, &M);
	for (int j = 0; j < M; j++)
	{
		int l, r;
		scanf("%d%d", &l, &r);

		if (l > r)
		{
			int tmp = l;
			l = r;
			r = tmp;
		}

		top++;
		tt[top].left = l;
		tt[top].right = r;

		for (int i = 0; i <= top-1; i++)
		{
			if (tt[i].left != -1)
			{
				if (l <= tt[i].left && r >= tt[i].left && r <= tt[i].right)
				{
					tt[top].right = tt[i].right;
					tt[i].left = -1;
				}
				else if (l <= tt[i].left && r >= tt[i].right)
				{
					tt[i].left = -1;
				}
				else if (l >= tt[i].left && r <= tt[i].right)
				{
					tt[top].left = tt[i].left;
					tt[top].right = tt[i].right;
					tt[i].left = -1;
				}
				else if (l >= tt[i].left && l <= tt[i].right  && r >= tt[i].right)
				{
					tt[top].left = tt[i].left;
					tt[i].left = -1;
				}
				else if (r == tt[i].left)
				{
					tt[top].left = tt[i].left;
					tt[i].left = -1;
				}
				else if (l == tt[i].right)
				{
					tt[top].right = tt[i].right;
					tt[i].left = -1;
				}
			}

		}
	}

	int result = L + 1;
	for (int i = 0; i <= top; i++)
	{
		if (tt[i].left != -1)
		{
			result -= (tt[i].right - tt[i].left + 1);
		}
	}

	printf("%d\n", result);
}