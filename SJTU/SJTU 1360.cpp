#include<iostream>
#include<cstdio>

using namespace std;

int startTime[100010] = { 0 };
int endTime[100010] = { 0 };
int cnt = 0;
int N;

void qs(int l, int r, int a[], int b[])
{
	int i, j, mid, t;
	i = l; j = r; mid = a[(i + j) / 2];
	while (i <= j)
	{
		while (a[j]>mid) j--;
		while (a[i]<mid) i++;
		if (i <= j)
		{
			t = a[i]; a[i] = a[j]; a[j] = t;
			t = b[i]; b[i] = b[j]; b[j] = t;
			i++; j--;
		}
	}
	if (l<j) qs(l, j, a, b);
	if (i<r) qs(i, r, a, b);
}

int main()
{
	cin >> N;
	for(int i=1;i<=N;i++)
	{
		scanf("%d", &startTime[i]);
		scanf("%d", &endTime[i]);
	}

	// 按照结束时间进行排序
	qs(1, N, endTime, startTime);
	int end = 0;
	for(int i=1;i<=N;i++)
	{
		if (startTime[i] >= end)
		{
			cnt++;
			end = endTime[i];
		}
	}
	cout << cnt << endl;
	return 0;
}