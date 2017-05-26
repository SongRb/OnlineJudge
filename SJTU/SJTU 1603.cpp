#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int arr[100005];
int res[100005];

int N;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	memset(res, 0, sizeof(res));

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] > arr[j]) res[i]++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d ", res[i]);
	}
}