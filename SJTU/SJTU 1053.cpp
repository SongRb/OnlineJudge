#include <iostream>
#include <cstdio>

using namespace std;

struct Node
{
	int x;
	int y;
	int v;
	Node() {}
	Node(int xx, int yy, int vv) :x(xx), y(yy), v(vv) {}
};


Node mem[10000];
int memTop = -1;

// 下标代表现在的值，储存的值代表初始值
int xPro[100000];
int yPro[100000];

void switchRow(int x, int y)
{
	int tmp = xPro[x];
	xPro[x] = xPro[y];
	xPro[y] = tmp;
}

void switchCol(int x, int y)
{
	int tmp = yPro[x];
	yPro[x] = yPro[y];
	yPro[y] = tmp;
}

int readValue(int x, int y)
{
	for (int i = 0; i <= memTop; i++)
	{
		if (mem[i].x == xPro[x] && mem[i].y == yPro[y]) return mem[i].v;
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d\n", &n);

	for (int i = 0; i < 100000; i++)
	{
		xPro[i] = i;
		yPro[i] = i;
	}

	for (memTop = 0; memTop < n; memTop++)
	{
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		getchar();
		mem[memTop].v = v;
		mem[memTop].x = x;
		mem[memTop].y = y;
	}

	int m;
	scanf("%d\n", &m);
	for (int i = 0; i < m; i++)
	{
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		switch (op)
		{
		case 0:
			switchRow(x, y);
			break;
		case 1:
			switchCol(x, y);
			break;
		case 2:
			printf("%d\n", readValue(x, y));
			break;
		default:
			break;
		}
	}
	//system("pause");

}