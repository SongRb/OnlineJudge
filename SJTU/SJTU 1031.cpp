#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int N;
int matrix[105][105];

int dX[] = { 1,0,-1,0 };
int dY[] = { 0,1,0,-1 };

int visited[105][105];

struct Point
{
	int x;
	int y;
	Point(int xx, int yy) :x(xx), y(yy) {}
};

bool BFS(int left, int right)
{
	if (matrix[0][0]<left || matrix[0][0]>right) return false;

	queue<Point> q;
	q.push(Point(0, 0));

	memset(visited, 0, sizeof(visited));
	visited[0][0] = 1;

	while (!q.empty())
	{
		Point p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int newX = p.x + dX[i];
			int newY = p.y + dY[i];
			if (newX >= 0 && newX < N && newY >= 0 && newY < N && !visited[newX][newY])
			{
				visited[newX][newY] = 1;
				if (matrix[newX][newY] >= left && matrix[newX][newY] <= right)
				{

					q.push(Point(newX, newY));

					if (newX == N - 1 && newY == N - 1)
						return true;

				}
			}
		}
	}
	return false;
}

bool check(int dis)
{
	for (int left = 0; left + dis <= 110; left++)
	{
		if (BFS(left, left + dis))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j <N; j++)
			scanf("%d", &matrix[i][j]);
	int L = 0, R = 110;
	// BinarySearch
	while (R>L)
	{
		int mid = (R + L) >> 1;
		if (check(mid)) R = mid;
		else L = mid + 1;
	}

	printf("%d\n", R);
	return 0;
}