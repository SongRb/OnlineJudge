#include<iostream>
#include <cstdio>
using namespace std;
int N;
int preLength[3000] = { 0 };

int main()
{
	scanf("%d", &N);

	int sum = 0;
	long long int result = 0;
	int cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		int x;
		scanf("%d", &x);
		preLength[i] = preLength[i - 1] + x;
		sum += x;
	}
	for (int i = 0; i <= N - 2; ++i)
	{
		for (int j = i + 1; j <= N - 1; ++j)
		{
			if ((preLength[j] - preLength[i]) == sum / 2)
				cnt++;
		}
	}
	result = cnt*(cnt - 1) / 2;
	printf("%d", result);
	return 0;
}