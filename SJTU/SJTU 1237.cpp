#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<int> graph[10005];
vector<int> noParPoint;

int inDegree[10005];

int main()
{
	int n, m;
	memset(inDegree, 0, sizeof(inDegree));

	queue<int> zeroDegree;

	queue<int> zDegree[2];
	int cur = 0, next = 1;

	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		graph[b].push_back(a);
		inDegree[a]++;
	}

	int times = 1;
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			//zeroDegree.push(i);
			zDegree[cur].push(i);
		}
	}

	while (!zDegree[0].empty() || !zDegree[1].empty())
	{
			int curNode = zDegree[cur].front();
			inDegree[curNode]--;

			for (int i = 0; i < graph[curNode].size(); i++)
			{
				int subNode = graph[curNode][i];
				inDegree[subNode]--;
				if (inDegree[subNode] == 0)
					zDegree[next].push(subNode);
			}
			zDegree[cur].pop();

			if (zDegree[cur].empty() && !zDegree[next].empty())
			{
				cur = next;
				next = 1 - cur;
				times++;
			}
	}

	printf("%d\n", times);
	return 0;
}