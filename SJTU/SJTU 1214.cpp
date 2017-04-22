#include <iostream>

using namespace std;

struct Node
{

    int value;
    int left;
    Node *next;

    int parent;
    int right;

    int brother;


    Node(int v, int l = NULL, int b = NULL)
    {
        value = v;
        left = l;
        brother = b;
        next = NULL;
    }


    Node(const Node *p)
    {
        value = p->value;
        left = p->left;
        brother = p->brother;
    }
};


Node *tree[100005];
int hasPar[100005];

void bfsOrder(Node *floor)
{
    Node *nextP = new Node(0, -1, 0);
    if (!floor) return;
    Node *p = floor;
    Node *q = nextP;
    do
    {
        Node *tmpB = p;
        while (tmpB)
        {
            cout << tmpB->value << ' ';
            if (tmpB->left)
            {
                if (q->left != -1)
                {
                    q->next = tree[tmpB->left];
                    q = q->next;
                } else
                {
                    nextP = tree[tmpB->left];
                    q = nextP;
                }
            }
            tmpB = tree[tmpB->brother];
        }

        p = p->next;
    } while (p);
    if (q->left != -1)
    {
        q->next = NULL;
        bfsOrder(nextP);
    } else
    {
        return;
    }


}

void preOrder(Node *p)
{
    if (p == NULL)
        return;
    else
    {
        cout << p->value << ' ';
        Node *tmpB = tree[p->left];
        while (tmpB)
        {
            preOrder(tmpB);
            tmpB = tree[tmpB->brother];
        }
    }
}


void postOrder(Node *p)
{
    if (p == NULL)
        return;
    else
    {
        Node *tmpB = tree[p->left];
        while (tmpB)
        {
            postOrder(tmpB);
            tmpB = tree[tmpB->brother];
        }
        cout << p->value << ' ';
    }
}


int main()
{
    int num;
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        hasPar[i] = 0;
    }

    tree[0] = NULL;


    for (int i = 1; i <= num; i++)
    {
        int leftNode, bro, value;
        cin >> leftNode >> bro >> value;
        hasPar[leftNode]++;
        hasPar[bro]++;

        tree[i] = new Node(value, leftNode, bro);
    }

    int i = 1;
    for (; i <= num; i++)
    {
        if (hasPar[i] == 0)
            break;
    }


    preOrder(tree[i]);
    cout << endl;

    postOrder(tree[i]);
    cout << endl;

    bfsOrder(tree[i]);
    cout << endl;
    return 0;
}



