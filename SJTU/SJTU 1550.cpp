# include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int height[10055] = { 0 };

	int n, cnt = -1, tmpNum = 0;
	scanf("%d", &n);
	int maxHeight = 0, maxIndex = 0;
	char ch;
	scanf("%c", &ch);
	while (ch!=']')
	{
		if (ch == ',' || ch == ']')
		{
			height[++cnt] = tmpNum;
			if (maxHeight <= tmpNum)
			{
				maxHeight = tmpNum;
				maxIndex = cnt;
			}
			tmpNum = 0;
		}
		else if (ch >= '0' && ch <= '9')
		{
			tmpNum = tmpNum * 10 + (ch - '0');
		}
	}
	height[n] = -1;

	if (n == 1)
	{
		printf("0");
		return 0;
	}

	int insLimitIndex[1005] = { 0 };
	int insLimitIndexTop = -1;

	insLimitIndex[++insLimitIndexTop] = n;

	if (height[0] >= height[1])
	{
		insLimitIndex[++insLimitIndexTop] = 0;
	}

	for (int i = 1; i <= maxIndex; i++)
	{
		if (height[i] >= height[i - 1] && height[i] >= height[i + 1] && height[i] >= height[insLimitIndex[insLimitIndexTop]])
		{
			insLimitIndex[++insLimitIndexTop] = i;
		}
	}

	int desLimitIndex[1005] = { 0 };
	int desLimitIndexTop = -1;

	desLimitIndex[++desLimitIndexTop] = n;

	if (height[n - 1] >= height[n - 2])
	{
		desLimitIndex[++desLimitIndexTop] = n - 1;
	}

	for (int i = n - 2; i > maxIndex; i--)
	{
		if (height[i] >= height[i - 1] && height[i] >= height[i + 1] && height[i] >= height[desLimitIndex[desLimitIndexTop]])
		{
			desLimitIndex[++desLimitIndexTop] = i;
		}
	}


	int limitIndex[1005] = { 0 };
	int limitIndexTop = -1;
	for (int i = 1; i <= insLimitIndexTop; i++)
		limitIndex[++limitIndexTop] = insLimitIndex[i];
	for (int i = desLimitIndexTop; i >= 1; i--)
		limitIndex[++limitIndexTop] = desLimitIndex[i];

	int result = 0;
	for (int i = 0; i < limitIndexTop; i++)
	{
		int minHeight = height[limitIndex[i]] < height[limitIndex[i + 1]]? height[limitIndex[i]]: height[limitIndex[i + 1]];
		for (int j = limitIndex[i] + 1; j < limitIndex[i + 1]; j++)
		{
			if (minHeight - height[j] > 0)
				result += minHeight - height[j];
		}
	}
	printf("%d", result);
}