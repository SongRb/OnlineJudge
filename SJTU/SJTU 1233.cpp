#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int> to[12];
int visited[12];

int M;
int result = 0;

void DFS(int p, int depth)
{
	if (depth == M)
	{
		result++;
		visited[p] = 0;
		return;
	}
	else if (depth > M) return;

	visited[p] = 1;

	for (int i = 0; i < to[p].size(); i++)
	{
		int tmp = to[p][i];
		if (!visited[tmp])
		{
			visited[tmp] = 1;
			DFS(tmp, depth + 1);
			visited[tmp] = 0;
		}
	}
	visited[p] = 0;

}

int main()
{
	int n, m, start;
	scanf("%d%d%d%d", &n, &m, &start, &M);

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		to[a].push_back(b);
	}

	DFS(start, 0);

	printf("%d\n", result);
	return 0;
}