#include <cstdio>
struct IO
{
	int time;
	bool in;
};

IO station[10003];

void qsort(IO* arr, int left, int right)
{
	int i = left, j = right, t = arr[i].time;
	bool record = arr[i].in;
	while (i < j)
	{
		while (i < j && arr[j].time >= t) --j;
		arr[i] = arr[j];
		while (i < j && arr[i].time <= t) ++i;
		arr[j] = arr[i];
	}
	arr[i].time = t; arr[i].in = record;

	if(left <i-1)
	qsort(arr, left, i - 1);
	if(i+1<right)
	qsort(arr, i + 1, right);
}

int main()
{
	int n, i;
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i)
	{
		int inTime, outTime;
		scanf("%d%d", &inTime, &outTime);
		station[i * 2].time = inTime;
		station[i * 2].in = true;
		station[i * 2 + 1].time = outTime;
		station[i * 2 + 1].in = false;
	}
	n *= 2;
	qsort(station, 0, n - 1);
	int inFlag, outFlag = 0, maxExLength = 0, maxNoLength = 0;
	int num = 0;
	for (i = 0; i < n; ++i)
	{
		if (station[i].in)
		{
			num++;

			if (num == 1 && station[i].in)
			{
				inFlag = station[i].time;
				if (outFlag != 0 && station[i].time - outFlag > maxNoLength) maxNoLength = station[i].time - outFlag;
			}

		}
		else
		{
			num--;
			if (num == 0)
			{
				outFlag = station[i].time;
				if (station[i].time - inFlag > maxExLength) maxExLength = station[i].time - inFlag;
			}
		}

	}
	printf("%d\n%d", maxExLength, maxNoLength);
}