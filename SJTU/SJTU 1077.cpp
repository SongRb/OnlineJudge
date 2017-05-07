#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

#define  LL long long int

using namespace std;

const int arrLength = 35;

LL result[arrLength][arrLength];
int path[arrLength][arrLength];
LL in[arrLength];

LL search(int x, int y)
{
	if (x > y)
	{
		result[x][y] = 1;
		path[x][y] = 0;
		return result[x][y];
	}

	if (result[x][y] != -1) return result[x][y];

	if (x == y)
	{
		result[x][y] = in[x];
		path[x][y] = x;
		return in[x];
	}

	result[x][y] = 0;
	for (int i = x; i <= y; i++)
	{
		search(x, i - 1);
		search(i + 1, y);
		int res = result[x][i - 1] * result[i + 1][y] + in[i];
		if (res > result[x][y])
		{
			path[x][y] = i;
			result[x][y] = res;
		}
	}
	return result[x][y];

}

void preOrder(int x, int y)
{
	if (x > y) return;
	else
	{
		printf("%d ", path[x][y]);
		preOrder(x, path[x][y] - 1);
		preOrder(path[x][y] + 1, y);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	memset(result, -1, sizeof(result));

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &in[i]);
	}
	search(1, n);
	printf("%lld\n", result[1][n]);
	preOrder(1, n);
}