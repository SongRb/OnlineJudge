#include <iostream>
#include <cstdio>

using namespace std;

int lChild[100005] = {0};
int rChild[100005] = {0};

int parent[100005] = {0};

void preOrder(int r)
{
    if (r == 0) return;
    cout << r << ' ';
    if (lChild[r]) preOrder(lChild[r]);
    if (rChild[r]) preOrder(rChild[r]);
}


int main()
{
    int m;
    cin >> m;
    parent[1] = -1;
    for (int i = 0; i < m; i++)
    {
        int command;

        scanf("%d", &command);
        if (command == 1)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);

            if (parent[a] == 0 || lChild[a] != 0 || rChild[a] != 0 || parent[b] != 0 || parent[c] != 0 || b == c)
            {

                printf("Error!\n");
                continue;
            } else
            {
                lChild[a] = b;
                rChild[a] = c;
                parent[b] = a;
                parent[c] = a;
                printf("Ok!\n");
            }

        } else if (command == 2)
        {
            int a;
            scanf("%d", &a);

            if (parent[a] == 0)
            {
                printf("Error!\n");

                continue;
            } else if (parent[a] == -1)
            {
                printf("%d %d %d\n", 0, lChild[a], rChild[a]);
            } else
            {
                printf("%d %d %d\n", parent[a], lChild[a], rChild[a]);
            }
        } else if (command == 3)
        {
            int a;
            scanf("%d", &a);
            if (a == 1 || parent[a] == 0)
            {
                printf("Error!\n");
                continue;
            } else
            {
                if (lChild[parent[a]] == a) printf("%d\n", rChild[parent[a]]);
                else printf("%d\n", lChild[parent[a]]);

                int tmp = lChild[parent[a]];
                lChild[parent[a]] = rChild[parent[a]];
                rChild[parent[a]] = tmp;
            }
        }
    }
    preOrder(1);
}