#include <iostream>
#include <cstdio>
#include <queue>


using namespace std;

struct Edge
{
	int from;
	int to;
	int cost;
	friend bool operator<(const Edge& a, const Edge& b)
	{
		return a.cost > b.cost;
	}
};

int father[10005];

int findFather(int x)
{
	father[x] =  father[x] == x ? x : findFather(father[x]);
	return father[x];
}



int main()
{
	priority_queue<Edge> que;

	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b, p;
		Edge e;
		scanf("%d%d%d", &e.from, &e.to, &e.cost);
		que.push(e);
	}

	for (int i = 0; i < 10005; i++)
	{
		father[i] = i;
	}

	int num = 0;
	int result = 0;
	while (!que.empty() && num < n - 1)
	{

		Edge e = que.top();
		que.pop();
		int fx = findFather(e.from);
		int fy = findFather(e.to);

		if (fx != fy)
		{
			father[fy] = findFather(father[fx]);
			result += e.cost;
			num++;
		}
	}

	printf("%d\n", result);
}