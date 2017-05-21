#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void leftToRight(const int array[], int liss[], int length)
{
	int i, j;

	//记录当前各元素作为最大元素的最长递增序列长度  
	//unsigned int liss[length];

	for (i = 0; i < length; ++i)
	{
		liss[i] = 1;
	}

	for (i = 1; i < length; ++i)
	{
		//找到以array[i]为最末元素的最长递增子序列  
		for (j = 0; j < i; ++j)
		{
			//如果要求非递减子序列只需将array[j] < array[i]改成<=，  
			//如果要求递减子序列只需改为>  
			if (array[j] < array[i] && liss[j] + 1> liss[i])
			{
				liss[i] = liss[j] + 1;
			}
		}
	}
}

void rightToLeft(const int array[], int liss[], int length)
{
	int i, j;

	//记录当前各元素作为最大元素的最长递增序列长度  
	//unsigned int liss[length];

	for (i = 0; i < length; ++i)
	{
		liss[i] = 1;
	}

	for (i = length-2; i>=0; --i)
	{
		//找到以array[i]为最末元素的最长递增子序列  
		for (j = length-1; j > i; --j)
		{
			//printf("i j: %d %d\n", i, j);
			//如果要求非递减子序列只需将array[j] < array[i]改成<=，  
			//如果要求递减子序列只需改为>  
			if (array[j] < array[i] && liss[j] + 1> liss[i])
			{
				liss[i] = liss[j] + 1;
				//得到当前最长递增子序列的长度，以及该子序列的最末元素的位置  
			}
		}
	}
}

int main()
{
	int boys[105];
	int length = 5;
	scanf("%d", &length);

	for (int i = 0; i < length; i++)
		scanf("%d", &boys[i]);

	int rArray[105];
	int lArray[105];

	rightToLeft(boys, rArray, length);
	leftToRight(boys, lArray, length);

	int max = -1;
	for (int i = 0; i < length; i++)
	{
		int tmp = rArray[i] + lArray[i] - 1;
		if (max < tmp) max = tmp;
	}

	printf("%d", length - max);

}