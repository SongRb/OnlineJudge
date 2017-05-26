#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct Edge
{
	int distance;
	int cost;
	int to;

	Edge() {}

	Edge(int t,int d, int c) :distance(d), cost(c), to(t) {}
};

bool visited[1005];
vector<Edge> graph[1005];

int minDistance = 1000000;
int minCost = 1000000;

int startNode;
int endNode;

void DFS(int p, int d, int c)
{
	if (d > minDistance)
		return;
	if (p == endNode)
	{
		if (d < minDistance)
		{
			minDistance = d;
			minCost = c;
		}
		else if (d == minDistance && c<minCost)
		{
			minCost = c;
		}
		return;
	}

	visited[p] = true;
	for (int i = 0; i < graph[p].size(); i++)
	{
		int node = graph[p][i].to;

		if (!visited[node])
		{
			int dis = graph[p][i].distance;
			int cost = graph[p][i].cost;
			visited[node] = true;
			DFS(node,d+dis,c+cost);
			visited[node] = false;
		}
	}
}


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < m; i++)
	{
		int a, b, d, p;
		scanf("%d%d%d%d", &a, &b, &d, &p);

		graph[a].push_back(Edge(b, d, p));
		graph[b].push_back(Edge(a, d, p));
	}

	scanf("%d%d", &startNode, &endNode);

	DFS(startNode, 0, 0);


	printf("%d %d\n", minDistance, minCost);
	system("pause");
	return 0;
}