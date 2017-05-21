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

	Edge(int t,int w):to(t),weight(w){}
};

vector<Edge> graph[12];
bool visited[12];
int dist[12];

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

	visited[start] = true;
	dist[start] = 0;

	queue<int> que;
	que.push(start);

	while (!que.empty())
	{
		int tmp = que.front();
		que.pop();
		visited[tmp] = false;

		for (int i = 0; i < graph[tmp].size(); i++)
		{
			int to = graph[tmp][i].to;
			int weight = graph[tmp][i].weight;
			if (dist[to] > weight + dist[tmp])
			{
				dist[to] = weight + dist[tmp];

				if (!visited[to])
				{
					visited[to] = true;
					que.push(to);
				}
			}
		}
	}
	printf("%d", dist[end]);
	return 0;


}