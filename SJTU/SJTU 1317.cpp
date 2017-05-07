#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int stalls[205];

int main()
{
	int M, C, S;
	scanf("%d%d%d", &M, &S, &C);

	int maxIndex = -1, minIndex = 210;
	memset(stalls, 0, sizeof(stalls));
	for (int i = 0; i < C; i++)
	{
		int index;
		scanf("%d", &index);
		stalls[index] = 1;
		if (maxIndex < index) maxIndex = index;
		if (minIndex > index) minIndex = index;
	}

	priority_queue<int> test;

	int result = maxIndex - minIndex + 1;

	for (int i = minIndex; i <= maxIndex; i++)
	{
		int mask = 0;
		if (stalls[i] == 0)
		{
			while (stalls[i] == 0)
			{
				mask++;
				i++;
				if (i > maxIndex)
					break;
			}
		}
		test.push(mask);
	}


	for (int i = 1; i < M; i++)
	{
		result -= test.top();
		test.pop();
		if (test.empty()) break;
	}

	printf("%d", result);
	return 0;
}