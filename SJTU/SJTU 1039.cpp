#include <cstdio>
#include <iostream>

struct Node
{
    int par;
    int index;
    int left;
    int right;

    Node() { index = -1; }
};

Node tree[30005];

int getIndex(int i)
{
    int par = tree[i].par;
    if (tree[i].index == -1)
    {
        if (tree[par].left == i) return getIndex(par) * 2;
        else return getIndex(par) * 2 + 1;
    } else return tree[i].index;
}

void postOrder(int r)
{
    if (r == -1) return;
    postOrder(tree[r].left);
    postOrder(tree[r].right);
    printf("%d ", r);
}

int main()
{
    int num;
    scanf("%d", &num);


    for (int i = 0; i <= num - 1; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        tree[x].left = y;
        tree[x].right = z;
        tree[y].par = x;
        tree[z].par = x;
    }

    tree[1].index = 1;

    for (int i = 1; i <= num; i++)
    {
        printf("%d ", getIndex(i));
    }
    printf("\n");
    postOrder(1);
    return 0;
}