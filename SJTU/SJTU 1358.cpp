#include <iostream>
#include <cstdio>


using namespace std;

int N;

struct Node
{
    int data;
    int subTreeNum = -1;
    Node *next;

    Node() : next(NULL), data(0) {}

    Node(int d, Node *n) : data(d), next(n) {}
};


Node tree[100005];
bool conNodeNum[100005] = {0};

void addAdjNode(int x, int y)
{
    tree[x].next = new Node(y, tree[x].next);
}

int depSearch(int node, int par)
{
    int sum = 1;
    Node *p = tree[node].next;
    Node *parP = NULL;
    while (p)
    {
        if (p->data != par)
        {
            if (p->subTreeNum == -1)
                p->subTreeNum = depSearch(p->data, node);
            sum += p->subTreeNum;
        } else parP = p;
        p = p->next;
    }

    if (parP) parP->subTreeNum = N - sum;

    return sum;
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);

        addAdjNode(x, y);
        addAdjNode(y, x);

        conNodeNum[x]++;
        conNodeNum[y]++;
    }

    int leafIndex = 1;
    for (; leafIndex <= N; leafIndex++)
    {
        if (conNodeNum[leafIndex] == 1) break;
    }

    depSearch(leafIndex, 0);

    for (int i = 1; i <= N; i++)
    {
        Node *p = tree[i].next;
        // �˴���֦���������ֻ�������ڵ���ô�죿
        //if (p->next != NULL)
        //{
        bool accepted = true;
        while (p)
        {
            if (p->subTreeNum > N / 2)
            {
                accepted = false;
                break;
            }
            p = p->next;
        }
        if (accepted) printf("%d\n", i);
        //}
    }

    //system("pause");

    return 0;
}