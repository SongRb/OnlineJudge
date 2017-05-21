#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void leftToRight(const int array[], int liss[], int length)
{
	int i, j;

	//��¼��ǰ��Ԫ����Ϊ���Ԫ�ص���������г���  
	//unsigned int liss[length];

	for (i = 0; i < length; ++i)
	{
		liss[i] = 1;
	}

	for (i = 1; i < length; ++i)
	{
		//�ҵ���array[i]Ϊ��ĩԪ�ص������������  
		for (j = 0; j < i; ++j)
		{
			//���Ҫ��ǵݼ�������ֻ�轫array[j] < array[i]�ĳ�<=��  
			//���Ҫ��ݼ�������ֻ���Ϊ>  
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

	//��¼��ǰ��Ԫ����Ϊ���Ԫ�ص���������г���  
	//unsigned int liss[length];

	for (i = 0; i < length; ++i)
	{
		liss[i] = 1;
	}

	for (i = length-2; i>=0; --i)
	{
		//�ҵ���array[i]Ϊ��ĩԪ�ص������������  
		for (j = length-1; j > i; --j)
		{
			//printf("i j: %d %d\n", i, j);
			//���Ҫ��ǵݼ�������ֻ�轫array[j] < array[i]�ĳ�<=��  
			//���Ҫ��ݼ�������ֻ���Ϊ>  
			if (array[j] < array[i] && liss[j] + 1> liss[i])
			{
				liss[i] = liss[j] + 1;
				//�õ���ǰ����������еĳ��ȣ��Լ��������е���ĩԪ�ص�λ��  
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