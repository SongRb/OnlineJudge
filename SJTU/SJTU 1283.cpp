#include <iostream>
#include <cstdio>
#include<cstring>

int pre[1000];

int num[300];
int len = 1;

// find root element
int find(int x)
{
	int res = x;
	while (res != pre[res])
	{
		res = pre[res];
	}

	while (x != res)
	{
		int preN = pre[x];
		pre[x] = res;
		x = preN;
	}

	return res;
}

// join two point
void join(int x, int y)
{
	int rX = find(x);
	int rY = find(y);

	if (rX != rY)
	{
		pre[rX] = rY;
	}
}

// get power of 2
void pow(int p)
{
	memset(num, 0, sizeof(num));
	num[0] = 1;

	for (int i = 0; i < p; i++)
	{
		int carry = 0;
		for (int j = 0; j < len; j++)
		{
			int tmp = num[j] * 2 + carry;
			num[j] = tmp % 10;
			carry = tmp / 10;
		}
		if (carry != 0)
			num[len++] = carry;
	}

}


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)
		pre[i] = i;


	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		join(a, b);
	}

	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		if (pre[i] == i)
			k++;
	}


	pow(n - k);
	for (int i = len - 1; i >= 0; i--)
	{
		printf("%d", num[i]);
	}
	printf("\n");
}