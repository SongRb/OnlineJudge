#include <iostream>
#include <cstdio>

using namespace std;

struct Node
{

    int value;
    int right;
    int left;

    int nodeNum;
    int redNum;

    // false is white
    bool color;

    Node *next;


    Node(int d, int l = NULL, int r = NULL) : value(d), left(l), right(r), color(0), redNum(-1)
    {
        next = NULL;
        nodeNum = -1;
    }

    Node(const Node *p)
    {
        value = p->value;
        left = p->left;
        right = p->right;
    }
};

Node *tree[100005];
int hasPar[100005];

int bulbRank = 0;
int rankFlag = 0;

int getNodeNum(Node *p)
{
    if (p)
    {
        if (p->nodeNum != -1) return p->nodeNum;
        p->nodeNum = 1 + getNodeNum(tree[p->right]) + getNodeNum(tree[p->left]);
        return p->nodeNum;
    } else return 0;
}

void inOrderTrav(Node *p, int rankNum)
{
    if (p)
    {
        int s = getNodeNum(p);

        int l = getNodeNum(tree[p->left]);
        int r = getNodeNum(tree[p->right]);

        rankNum = rankNum % s + 1;
        if (rankNum <= l) inOrderTrav(tree[p->left], rankNum - 1);
        else if (rankNum == l + 1)
        {
            p->color = 1;
            return;
        } else inOrderTrav(tree[p->right], rankNum - 1 - l - 1);
    }
    return;
}


int getRedNum(Node *p)
{
    if (p)
    {
        if (p->redNum != -1) return p->redNum;
        p->redNum = p->color + getRedNum(tree[p->right]) + getRedNum(tree[p->left]);
        return p->redNum;
    } else return 0;
}


int main()
{
    int bulbNum, colorTimes, quesNum;
    //cin >> bulbNum >> colorTimes >> quesNum;
    scanf("%d%d%d", &bulbNum, &colorTimes, &quesNum);

    for (int i = 1; i <= bulbNum; i++)
    {
        hasPar[i] = 0;
    }

    tree[0] = NULL;
    for (int i = 1; i <= bulbNum; i++)
    {
        int num, leftNode, rightNode;
        //cin >> num >> leftNode >> rightNode;
        scanf("%d%d%d", &num, &leftNode, &rightNode);
        hasPar[leftNode]++;
        hasPar[rightNode]++;
        tree[num] = new Node(num, leftNode, rightNode);
    }

    int i = 1;
    for (; i <= bulbNum; i++)
    {
        if (hasPar[i] == 0)
            break;
    }

    for (int j = 0; j < colorTimes; j++)
    {
        int t, x;
        /*cin >> t >> x;*/
        scanf("%d%d", &t, &x);
        bulbRank = 0;
        inOrderTrav(tree[t], x);
    }

    for (int j = 0; j < quesNum; j++)
    {
        int w;
        /*cin >> w;*/
        scanf("%d", &w);
        //cout << getRedNum(tree[w]) << endl;
        printf("%d\n", getRedNum(tree[w]));
    }

    return 0;
}

