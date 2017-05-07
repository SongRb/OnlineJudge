#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

#define LL long long int

using namespace std;

struct AI
{
	LL score;
	LL power;
	int num;
	AI(){}

};

bool cmp(const AI& a, const AI& b)
{
	if (a.score > b.score) return true;
	else if (a.score == b.score) return a.num < b.num;
	else return false;
}

AI players[200000];

int main()
{
	int N, R;
	scanf("%d%d", &N, &R);
	for (int i = 0; i < 2 * N; i++)
	{
		players[i].num = i+1;
		scanf("%ld", &players[i].score);
	}

	for (int i = 0; i < 2 * N; i++)
	{
		scanf("%ld", &players[i].power);
	}

	sort(players, players + 2 * N, cmp);
	for (int j = 0; j < R; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (players[2 * i].power > players[2 * i + 1].power)
				players[2 * i].score++;
			else players[2 * i + 1].score++;
		}
		sort(players, players + 2 * N, cmp);
	}

	for (int i = 0; i < 2 * N; i++)
	{
		printf("%ld ", players[i].num);
	}

	return 0;

}