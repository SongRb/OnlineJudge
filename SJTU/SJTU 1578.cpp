#include <cstdlib>
#include <cstdio>
#include <cstring>

char yard[1000][1000];

// 储存顺序为：上，下，左，右
int totalState[4][3];

int n, m;

void calcPoint(int i, int j, int r[])
{
	switch (yard[i][j])
	{
	case 'C':r[0]++; break;
	case 'D':r[1]++; break;
	case'M':r[2]++; break;
	default:
		break;
	}
}

void calcBranch(int i, int j, int branch[4][3])
{
	// 右下，左上，左下，右上
	int dX[4] = { 1,-1,1,-1 };
	int dY[4] = { 1,-1,-1,1 };

	for (int k = 0; k < 4; k++)
	{
		int ii = i, jj = j;
		while (ii >= 1 && ii <= n && jj >= 1 && jj <= m)
		{
			switch (yard[ii][jj])
			{
			case 'C':branch[k][0]++; break;
			case 'D':branch[k][1]++; break;
			case 'M':branch[k][2]++; break;
			default:
				break;
			}
			ii += dX[k];
			jj += dY[k];
		}
	}
}

int main()
{
	memset(totalState, 0, sizeof(totalState));

	int x, y;

	scanf("%d%d", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			yard[i][j] = getchar();
			if (yard[i][j] == 'H')
			{
				yard[i][j] = ' ';
				x = i;
				y = j;
			}
		}
		getchar();
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			// Up section
			if (i <=x  && ((j == y) || (j != y && ((i - x) / (j - y) >= 1 || (i - x) / (j - y) <= -1))))
				calcPoint(i, j, totalState[0]);
				//upSection[i][j]++;

			// Down section
			if (i >= x && ((j == y) || (j != y && ((i - x) / (j - y) >= 1 || (i - x) / (j - y) <= -1))))
				calcPoint(i, j, totalState[1]);
				//downSection[i][j]++;
			// Left section
			// 首先保证在左边区域
			// 其次考虑斜率情况 和 与目标点重合情况
			if (j <= y && ((j == y && i == x) || (j != y && double(i - x) / (j - y) <= 1 && double(i - x) / (j - y) >= -1)))
				calcPoint(i, j, totalState[2]);
				//leftSection[i][j]++;
			// Right section
			if (j >= y && ((j == y && i == x) ||( j != y && double(i - x) / (j - y) <= 1 && double(i - x) / (j - y) >= -1)))
				calcPoint(i, j, totalState[3]);
				//rightSection[i][j]++;
		}

	int N;
	scanf("%d", &N);
	getchar();
	for (int k = 0; k < N; k++)
	{
		// 右下，左上，左下，右上
		int oriBranch[4][3];
		int resBranch[4][3];
		memset(oriBranch, 0, sizeof(oriBranch));
		memset(resBranch, 0, sizeof(resBranch));

		int oriPos[3];
		int resPos[3];
		memset(oriPos, 0, sizeof(oriPos));
		memset(resPos, 0, sizeof(resPos));

		char command;
		scanf("%c", &command);
		getchar();
		if (command == 'N')
		{
			if (x - 1 >= 1)
			{
				calcBranch(x, y, oriBranch);
				calcPoint(x, y, oriPos);
				x--;
				calcBranch(x, y, resBranch);
				calcPoint(x, y, resPos);

				// 上
				for (int i = 0; i < 3; i++)
					totalState[0][i] -= oriBranch[1][i] + oriBranch[3][i] - oriPos[i];

				// 下
				for (int i = 0; i < 3; i++)
					totalState[1][i] += resBranch[0][i] + resBranch[2][i] - resPos[i];

				// 左
				for (int i = 0; i < 3; i++)
					totalState[2][i] += -oriBranch[2][i] + resBranch[1][i];


				// 右
				for (int i = 0; i < 3; i++)
					totalState[3][i] += -oriBranch[0][i] + resBranch[3][i];

				printf("%d %d %d\n", totalState[0][0], totalState[0][1], totalState[0][2]);
			}
			else continue;
		}
		else if (command == 'S')
		{
			if (x + 1 <= n)
			{
				calcBranch(x, y, oriBranch);
				calcPoint(x, y, oriPos);
				x++;
				calcBranch(x, y, resBranch);
				calcPoint(x, y, resPos);

				// 上
				for (int i = 0; i < 3; i++)
					totalState[0][i] += resBranch[1][i] + resBranch[3][i] - resPos[i];

				// 下
				for (int i = 0; i < 3; i++)
					totalState[1][i] -= oriBranch[0][i] + oriBranch[2][i] - oriPos[i];

				// 左
				for (int i = 0; i < 3; i++)
					totalState[2][i] += -oriBranch[1][i] + resBranch[2][i];

				// 右
				for (int i = 0; i < 3; i++)
					totalState[3][i] += -oriBranch[3][i] + resBranch[0][i];

				printf("%d %d %d\n", totalState[1][0], totalState[1][1], totalState[1][2]);

			}

			else continue;
		}
		else if (command == 'W')
		{
			if (y - 1 >= 1)
			{
				calcBranch(x, y, oriBranch);
				calcPoint(x, y, oriPos);
				y--;
				calcBranch(x, y, resBranch);
				calcPoint(x, y, resPos);

				// 上
				for (int i = 0; i < 3; i++)
				{
					totalState[0][i] += -oriBranch[3][i] + resBranch[1][i];
				}

				// 下
				for (int i = 0; i < 3; i++)
				{
					totalState[1][i] += -oriBranch[0][i]+resBranch[2][i];
				}


				// 左
				for (int i = 0; i < 3; i++)
				{
					totalState[2][i] -= oriBranch[1][i] + oriBranch[2][i] - oriPos[i];
				}

				// 右
				for (int i = 0; i < 3; i++)
				{
					totalState[3][i] += resBranch[0][i] + resBranch[3][i] - resPos[i];
				}
				printf("%d %d %d\n", totalState[2][0], totalState[2][1], totalState[2][2]);

			}
			else continue;
		}
		else if (command == 'E')
		{
			if (y + 1 <= m)
			{
				calcBranch(x, y, oriBranch);
				calcPoint(x, y, oriPos);
				y++;
				calcBranch(x, y, resBranch);
				calcPoint(x, y, resPos);

				// 上
				for (int i = 0; i < 3; i++)
					totalState[0][i] += resBranch[3][i] - oriBranch[1][i];

				// 下
				for (int i = 0; i < 3; i++)
					totalState[1][i] += resBranch[0][i] - oriBranch[2][i];


				// 左
				for (int i = 0; i < 3; i++)
					totalState[2][i] += resBranch[1][i] + resBranch[2][i] - resPos[i];

				// 右
				for (int i = 0; i < 3; i++)
					totalState[3][i] -= oriBranch[0][i] + oriBranch[3][i] - oriPos[i];

				printf("%d %d %d\n", totalState[3][0], totalState[3][1], totalState[3][2]);
			}
			else continue;
		}
	}
	return 0;
}