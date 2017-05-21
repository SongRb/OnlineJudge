#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int fruits[2][15000];


int main()
{
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int N;
		scanf("%d", &N);
		int k[8];
		for (int j = 1; j <= 7; j++)
			scanf("%d", &k[j]);

		int length = 8 * N;
		int curRow = 0;
		for (int j = 1; j <= length; j++)
			fruits[curRow][j] = j;

		int lastEat = 0;
		for (int j = 1; j <= 7; j++)
		{
			int periodLength = 2 * k[j] - 1;
			int periodNum = length / periodLength;
			int remainder = length % periodLength;

			int nextRow = 1 - curRow;
			int nextTop = 0;

			// end index of last priod
			int startIndex = length - remainder;
			if (remainder < k[j])
			{
				for (int m = startIndex+1; m <= length; m++)
				{
					fruits[nextRow][m - startIndex] = fruits[curRow][m];
				}

				if(periodNum)
				lastEat = fruits[curRow][startIndex];

				nextTop = remainder;

			}
			else
			{
				periodNum++;
				lastEat = fruits[curRow][length];
			}

			for (int m = 0; m < periodNum; m++)
			{
				for (int n = 1; n <= k[j] - 1; ++n)
				{
					fruits[nextRow][++nextTop] = fruits[curRow][m*periodLength + n];
				}
			}
			length = nextTop;
			curRow = nextRow;
		}
		printf("%d\n", lastEat);
	}
}