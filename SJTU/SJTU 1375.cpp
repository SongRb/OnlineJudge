#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> graph[40005];
int nodeDepth[40005];
int farther[40005];
bool visited[40005];

void DFS(int node, int par, int depth)
{
	nodeDepth[node] = depth;
	farther[node] = par;
	visited[node] = true;
	for (vector<int>::iterator it = graph[node].begin(); it != graph[node].end(); it++)
	{
		if (*it != par && !visited[*it])
		{
			DFS(*it, node, depth + 1);
		}
	}
	return;
}

int main()
{
	int n;
	int root;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		if (b != -1)
		{
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		else
		{
			root = a;
		}
	}

	DFS(root, -1, 1);

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int x, y;
		int result = 0;
		scanf("%d", &x);
		scanf("%d", &y);
		if (nodeDepth[x] > nodeDepth[y])
		{
			if (nodeDepth[x] - nodeDepth[y] > 10000)
			{
				result = 2;
			}
			else
			{
				int p = farther[x];
				while (p != -1)
				{
					if (p == y)
					{
						result = 2;
						break;
					}
					p = farther[p];
				}
			}
		}
		else if (nodeDepth[x] < nodeDepth[y])
		{
			if (nodeDepth[y] - nodeDepth[x] > 10000)
			{
				result = 1;
			}
			else
			{
				int p = farther[y];
				while (p != -1)
				{
					if (p == x)
					{
						result = 1;
						break;
					}
					p = farther[p];
				}
			}


		}

		printf("%d\n", result);
			
	}
	return 0;
}


