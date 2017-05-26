#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

char* dict[40000];

// ´¢´æ°´×ÖµäÐòÅÅÁÐµÄ×Ö·û´®µÄindex
int orderedDict[40000];


bool cmp(int i, int j)
{
	return strcmp(dict[i], dict[j]) < 0;
}


bool isPrefix(char *pre,int preLen ,char* word)
{
	if (preLen > strlen(word))
		return false;

	for (int i = 0; i < preLen; i++)
	{
		if (pre[i] != word[i])
			return false;
	}
	return true;
}


int findFirst(char* pre, int n)
{
	int prelen = strlen(pre);
	int pt1 = 0, pt2 = n - 1;
	int mid = n / 2;

	while (pt2 - pt1 > 10)
	{
		if (strcmp(pre, dict[orderedDict[mid]]) < 0)
		{
			pt2 = mid;
		}
		else
		{
			pt1 = mid;
		}
		mid = (pt2 + pt1) / 2;
	}

	for (int i = pt1; i <= pt2; i++)
	{
		if (isPrefix(pre, prelen, dict[orderedDict[i]]))
			return i;
	}

	return -1;


}


int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		dict[i] = new char[100];
		orderedDict[i] = i;
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%s", dict[i]);
	}


	sort(orderedDict, orderedDict + N, cmp);

	for (int j = 0; j < M; j++)
	{
		char prefix[1000];
		int x;
		scanf("%d%s", &x, prefix);

		int index = findFirst(prefix, N);

		if (index == -1)
		{
			printf("-1\n");
		}
		else
		{
			index += x - 1;
			if (index > N - 1)
			{
				printf("-1\n");

			}
			else if (isPrefix(prefix, strlen(prefix), dict[orderedDict[index]]))
			{
				printf("%d\n", orderedDict[index] + 1);
			}
			else
			{
				printf("-1\n");
			}
		}
	}
	return 0;
}