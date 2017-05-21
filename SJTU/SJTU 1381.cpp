#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int numToBCD[10] = { 6,2,5,5,4,5,6,3,7,6 };

int getDigitNum(int num)
{
	int digitNum = 1;
	int tmp = num / 10;
	while (tmp != 0)
	{
		digitNum++;
		tmp = tmp / 10;
	}
	return digitNum;
}

int findBCDNum(int num)
{
	if (num < 10)
		return numToBCD[num];

	int digitNum = getDigitNum(num);

	int result = 0;

	int currentS = pow(10,digitNum-1);
	while(currentS>0)
	{
		result += numToBCD[num / currentS];
		num %= currentS;
		currentS /= 10;
	}

	return result;
}

int main()
{
	int n;
	scanf("%d", &n);

	int matchNum = n - 3;
	int m = matchNum / 4;
	// ËùÓÐÊý
	int totalCnt = 0;
	for (int i = 0; i <= pow(10,m+1)-1; i++)
	{
		int sumDigitNum = findBCDNum(i);
		int digitNum = getDigitNum(i);

		if (sumDigitNum + digitNum*2 >= matchNum)
			continue;

		int cnt = 0;
		for (int j = 0; j <= i/2;j++)
		{
			if (sumDigitNum + findBCDNum(j) + findBCDNum(i - j) == matchNum)
				cnt++;
		}

		if (i % 2 == 0)
		{
			if (sumDigitNum + findBCDNum(i / 2) + findBCDNum(i / 2) == matchNum)
			{
				cnt = cnt * 2 - 1;
			}
			else
				cnt = cnt * 2;
		}
		else
		{
			cnt = cnt * 2;
		}
		totalCnt += cnt;
	}


	printf("%d", totalCnt);
}