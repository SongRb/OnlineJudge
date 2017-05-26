#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Node
{
	int parent;
	int near[4];
	Node(void)
	{
		memset(near, 0, sizeof(near));
	}
};

Node graph[1000001];
int num, A, B, layerNum, N, root;
bool visited[1000001] = { 0 };

// n*(n+1)
int mul[10000];

int pre[100000];

int findFloor(int x)
{
	int n = 1;
	while (2 * x > mul[n])
		n++;
	return n;
}


void addEdge(int a, int b)
{
	int aRoot = a, bRoot = b;

	while (graph[aRoot].parent > 0) aRoot = graph[aRoot].parent;
	while (graph[bRoot].parent > 0) bRoot = graph[bRoot].parent;

	if (aRoot != bRoot)
	{
		// 此处目的是让更多的点链到同一个节点上
		if (graph[aRoot].parent > graph[bRoot].parent)
		{
			graph[bRoot].parent += graph[aRoot].parent;

			while (graph[a].parent > 0 ) 
			{ 
				graph[a].parent = bRoot;
				a = graph[a].parent; 
			}

			int par = graph[bRoot].parent;
			while (graph[b].parent > 0) 
			{ 
				graph[b].parent = bRoot;
				b = graph[b].parent;
			}
			graph[bRoot].parent = par;

			graph[aRoot].parent = bRoot;
		}
		else
		{
			graph[aRoot].parent += graph[bRoot].parent;

			int par = graph[aRoot].parent;
			while (graph[a].parent > 0)
			{
				graph[a].parent = aRoot;
				a = graph[a].parent;
			}
			graph[aRoot].parent = par;

			while (graph[b].parent > 0)
			{
				graph[b].parent = aRoot;
				b = graph[b].parent;
			}

			graph[bRoot].parent = aRoot;
		}
	}
}


bool isConnected(int a, int b)
{
	int aRoot = a, bRoot = b;
	while (graph[aRoot].parent > 0)
		aRoot = graph[aRoot].parent;
	while (graph[bRoot].parent > 0)
		bRoot = graph[bRoot].parent;
	return aRoot == bRoot;
}


int findRoot(int x)
{
	int p = x;
	while (graph[p].parent > 0) p = graph[p].parent;
	return p;
}


void DFS(int p)
{
	if (p == B)
	{
		int result[1000];
		int resultTop = -1;
		while (p != A)
		{
			result[++resultTop] = p;
			p = pre[p];
		}

		result[++resultTop] = A;

		for (int i = resultTop; i >= 0; i--)
		{
			printf("%d ", result[i]);
		}
		return;
	}

	visited[p] = true;
	for (int i = 0; i < 4; i++)
	{
		int to = graph[p].near[i];
		if (to && !visited[to])
		{
			pre[to] = p;
			visited[to] = true;
			DFS(to);
			visited[to] = false;
		}
	}
}


int main()
{
	mul[1] = 2;
	for (int i = 2; i < 10000; i++)
	{
		mul[i] = mul[i - 1] + 2 * i;
	}

	int P, Q;
	bool flag = true;
	scanf("%d %d %d", &N, &A, &B);
	num = mul[N];
	for (int index = 1; index <= num; index++)
		graph[index].parent = -1;

	while (true)
	{
		scanf("%d %d", &P, &Q);
		layerNum = findFloor(P);
		switch (Q)
		{
		case 0:
		{
			if (findFloor(P - layerNum) == layerNum - 1)
			{
				addEdge(P, P - layerNum);
				graph[P].near[0] = P - layerNum;
				graph[P - layerNum].near[3] = P;
			}
			break;
		}
		case 1:
		{
			if (findFloor(P - layerNum + 1) == layerNum - 1)
			{
				addEdge(P, P - layerNum + 1);
				graph[P].near[1] = P - layerNum + 1;
				graph[P - layerNum + 1].near[2] = P;
			}
			break;
		}
		case 2:
		{
			if (findFloor(P + layerNum) <= N)
			{
				addEdge(P, P + layerNum);
				graph[P].near[2] = P + layerNum;
				graph[P + layerNum].near[1] = P;
			}
			break;
		}
		case 3:
		{
			if (findFloor(P + layerNum + 1) <= N)
			{
				addEdge(P, P + layerNum + 1);
				graph[P].near[3] = P + layerNum + 1;
				graph[P + layerNum + 1].near[0] = P;
			}
			break;
		}
		}

		if (isConnected(A, B))
			break;
	}


	DFS(A);
	return 0;
}