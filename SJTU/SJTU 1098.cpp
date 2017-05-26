#include <cstdio>
#include <cstring>
#include <iostream>

int x[105];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		if (m == 0)
		{
			printf("NO ODD SUBGRAPH\n");
			continue;
		}
		memset(x, 0, sizeof(x));

		bool found = false;
		int xx = 1000000, yy;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			x[a]++;
			x[b]++;

			if (a > b)
			{
				int tmp = a;
				a = b;
				b = a;
			}
			if (a < xx)
			{
				xx = a;
				yy = b;
			}
			else if (a == xx)
			{
				yy = b < yy ? b : yy;
			}
		}


		bool isOddGraph = true;
		for (int i = 1; i <= n; i++)
		{
			if (x[i] % 2 == 0)
			{
				isOddGraph = false;
				break;
			}
		}

		if (isOddGraph)
		{
			printf("ODD GRAPH\n");
		}
		else
		{
			printf("2 %d %d\n", xx, yy);
		}
	}
	return 0;
}