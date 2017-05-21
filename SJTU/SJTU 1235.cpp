#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 9999999;

struct Edge
{
	int to;
	int weight;

	Edge(int t, int w) :to(t), weight(w) {}

	friend bool operator<(const Edge& a, const Edge&b)
	{
		return a.weight > b.weight;
	}

};

vector<Edge> graph[10005];
bool visited[10005];

// 以下标表示的节点结束的最短路径加权和
int dist[10005];
// 在最短路径中下标表示的节点之前的节点
int preVer[10005];
// 以下标表示的节点结束的最短路径节点数量
int pathVerNum[10005];

int endNode;
void printAll(int x)
{
	if (preVer[x] != -1)printAll(preVer[x]);
	if (x == endNode)
	{
		printf("%d", x); return;
	}
	else
	{
		printf("%d ", x); return;
	}
}


int main()
{
	int n, m, start, end;
	scanf("%d%d%d%d", &n, &m, &start, &end);

	memset(visited, false, sizeof(visited));
	memset(dist, MAX, sizeof(dist));


	for (int i = 0; i < m; i++)
	{
		int a, b, p;
		scanf("%d%d%d", &a, &b, &p);
		graph[a].push_back(Edge(b, p));
	}



	// 此处Edge被用作最短路径
	priority_queue<Edge> heap;

	dist[start] = 0;
	heap.push(Edge(start,0));
	preVer[start] = -1;
	pathVerNum[start] = 1;

	for (int i = 1; i <= n; i++)
	{
		int minDist = MAX;
		int minNode = 0;
		while (true)
		{
			Edge tmp = heap.top();
			heap.pop();
			if (!visited[tmp.to])
			{
				minDist = tmp.weight;
				minNode = tmp.to;
				break;
			}
		}

		visited[minNode] = true;

		for (int j = 0; j < graph[minNode].size(); j++)
		{
			int to = graph[minNode][j].to;
			int weight = graph[minNode][j].weight;

			if (!visited[to] && minDist + weight < dist[to])
			{
				dist[to] = minDist + weight;
				heap.push(Edge(to, dist[to]));
				preVer[to] = minNode;
				pathVerNum[to] = pathVerNum[minNode] + 1;
			}
			else if (!visited[to] && minDist + weight == dist[to])
			{
				if (pathVerNum[to] > pathVerNum[minNode] + 1)
				{
					pathVerNum[to] = pathVerNum[minNode] + 1;
					preVer[to] = minNode;
				}
			}
		}
	}

	endNode = end;
	printf("%d\n", dist[end]);
	printAll(end);
	return 0;
}