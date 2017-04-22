#include <iostream>
#include <fstream>
#include <cstdio>


using namespace std;

// fisrt dimension: node
// second dimension: 0 for num, others for connected node
int tree[100005][1000];
int nodePar[100005];

void findParent(int n, int p)
{
    nodePar[n] = p;
    for (int i = 1; i <= tree[n][0]; i++)
    {
        if (tree[n][i] != p)
            findParent(tree[n][i], n);
    }
}

int main()
{
    //ifstream in("data.in");

    //streambuf *cinbuf = cin.rdbuf();
    //cin.rdbuf(in.rdbuf());

    int N, R;
    //cin >> N >> R;
    scanf("%d%d", &N, &R);

    for (int i = 0; i <= N; i++)
    {
        tree[i][0] = 0;
    }

    for (int i = 1; i < N; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        //cin >> x >> y;
        tree[x][++tree[x][0]] = y;
        tree[y][++tree[y][0]] = x;
    }

    findParent(R, -1);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int u;
        //cin >> u;
        scanf("%d", &u);
        int k = -1;
        for (int i = 1; i <= tree[u][0]; i++)
        {
            if (tree[u][i] != nodePar[u])
            {
                if (k < tree[u][i]) k = tree[u][i];
            }
        }
        printf("%d\n", k);
        //cout << k << endl;
    }
    //system("pause");

}