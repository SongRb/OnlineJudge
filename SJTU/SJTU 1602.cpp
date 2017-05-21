#include <iostream>
#include <cstdio>

short num1[10000];
short num2[10000];
short num3[20000];

void printArr(short num[], int length)
{
	for (int l = 0; l < length; l++)
	{
		printf("%hd ", num[l]);
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%hd", &num1[i]);
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%hd", &num2[i]);
	}

	if (n != 0 && m != 0)
	{
		int i = 0, j = 0, k = 0;
		while (true)
		{
			if (i >= n && j >= m)
				break;

			while (i < n && ((j < m && num1[i] <= num2[j]) || (j == m)))
			{
				num3[k++] = num1[i++];
			}

			while (j < m && ((i < n && num1[i] >= num2[j]) || (i == n)))
			{
				num3[k++] = num2[j++];
			}
		}
		printArr(num3, n + m);
	}

	else if (n == 0 && m != 0)
	{
		printArr(num2, m);
	}

	else if (n != 0 && m == 0)
	{
		printArr(num1, n);
	}
	//system("pause");
}