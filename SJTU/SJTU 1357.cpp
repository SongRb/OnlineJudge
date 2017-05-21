#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int path[7];
int dX[4] = { 0,1,0,-1 };
int dY[4] = { 1,0,-1,0 };

bool visited[25];

// 0 FOR H, 1 FOR J
int matrix[26];

// index in path
bool inPath(int index)
{
	for (int i = 0; i < 7; i++)
	{
		if (path[i] == index) return true;
		else if (path[i] > index) return false;
	}

	return false;
}


int check()
{
	memset(visited, 0, sizeof(visited));

	int test[50];
	int front = 0;
	int end = 0;
	test[end++] = path[0];

	int cnt = 0;
	int jNum = 0;

	jNum = matrix[path[0]];
	cnt++;
	visited[path[0]] = 1;

	while (front<end)
	{
		int curP = test[front++];

		for (int i = 0; i < 4; i++)
		{
			int tX = curP / 5 + dX[i];
			int tY = curP % 5 + dY[i];

			int nextP = tX * 5 + tY;

			if (inPath(nextP) && !visited[nextP] && tX >= 0 && tX < 5 && tY >= 0 && tY < 5)
			{
				visited[nextP] = 1;
				test[end++] = nextP;

				cnt++;
				jNum += matrix[nextP];
				visited[nextP] = 1;

				if (jNum - cnt + 7 < 4)
					return 0;
			}
		}
	}

	return cnt == 7 && jNum >= 4;
}

int main()
{
	memset(matrix, 0, sizeof(matrix));

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			char ch;
			cin >> ch;
			matrix[i * 5 + j] = ch == 'H' ? 0 : 1;
		}
	}

	int result = 0;
	for (path[0] = 0; path[0] <= 18; path[0]++)
		for (path[1] = path[0] + 1; path[1] <= 19; path[1]++)
			for (path[2] = path[1] + 1; path[2] <= 20; path[2]++)
				for (path[3] = path[2] + 1; path[3] <= 21; path[3]++)
					for (path[4] = path[3] + 1; path[4] <= 22; path[4]++)
						for (path[5] = path[4] + 1; path[5] <= 23; path[5]++)
							for (path[6] = path[5] + 1; path[6] <= 24; path[6]++)
							{
								result += check();
							}
	cout << result << endl;
}