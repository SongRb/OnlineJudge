#include <cstdio>
#include <iostream>

using namespace std;

const int MATDIM = 105;

int tree[MATDIM][MATDIM] = {0};

int des;

void search(int n, int p, int cost)
{
    if (n == des)printf("%d\n", cost);

    for (int i = 0; i < MATDIM; i++)
    {
        if (tree[n][i] && i != p)
        {
            search(i, n, cost + tree[n][i]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);


    for (int i = 1; i < n; i++)
    {
        int ai, bi, ci;
        scanf("%d%d%d", &ai, &bi, &ci);
        tree[ai][bi] = ci;
        tree[bi][ai] = ci;
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int dj;
        scanf("%d%d", &dj, &des);
        search(dj, -1, 0);
    }
    //system("pause");
}