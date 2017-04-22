#include <iostream>
#include <cstdio>

struct Node
{

    int value;
    int right;
    int left;
    //Node* left;
    //Node* right;
    Node *next;

    Node() : value(-1), right(-1), left(-1) { next = NULL; }

    Node(int d, int l = NULL, int r = NULL) : value(d), left(l), right(r)
    {
        next = NULL;
    }

    Node(const Node *p)
    {
        value = p->value;
        left = p->left;
        right = p->right;
    }
};

Node *tree[1000005];

bool bfsOrder(Node *floor, bool nullBrother)
{
    Node *nextP = new Node(-1, -2, -1);
    if (!floor) return true;
    Node *p = floor;
    Node *q = nextP;

    // ָ�����Ƿ�������ӽڵ�Ϊ�յ����
    bool nullChild = false;

    do
    {
        if (p->left != -1)
        {
            if (nullChild)
                return false;
            if (q->left != -2)
            {
                q->next = tree[p->left];
                q = q->next;
            } else
            {
                nextP = tree[p->left];
                q = nextP;
            }
        } else
        {
            nullChild = true;
        }

        if (p->right != -1)
        {
            if (nullChild)
                return false;

            if (q->left != -2)
            {
                q->next = tree[p->right];
                q = q->next;
            } else
            {
                nextP = tree[p->right];
                q = nextP;
            }
        } else
        {
            nullChild = true;
        }

        p = p->next;

    } while (p);


    if (q->left != -2 && !nullBrother)
    {
        q->next = NULL;
        bfsOrder(nextP, nullChild);
    } else if (q->left == -2)
    {
        return true;
    } else return false;
}


int main()
{
    int num;
    scanf("%d", &num);
    for (int i = 0; i <= num - 1; i++)
    {
        tree[i] = new Node();
    }

    for (int i = 1; i <= num - 1; i++)
    {
        int v;
        scanf("%d", &v);
        if (tree[v]->left == -1) tree[v]->left = i;
        else tree[v]->right = i;
    }

    if (bfsOrder(tree[0], false)) printf("true\n");
    else printf("false\n");

    //system("pause");

    return 0;
}