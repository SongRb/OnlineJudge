#include <iostream>

using namespace std;

struct Node
{

    int value;
    int right;
    int left;
    //Node* left;
    //Node* right;
    Node *next;


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

Node *tree[100005];
int hasPar[100005];


bool bfsOrder(Node *floor, bool nullBrother)
{
    Node *nextP = new Node(0, -1, 0);
    if (!floor) return true;
    Node *p = floor;
    Node *q = nextP;

    // ָ�����Ƿ�������ӽڵ�Ϊ�յ����
    bool nullChild = false;

    do
    {
        if (p->left)
        {
            if (nullChild)
                return false;
            if (q->left != -1)
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

        if (p->right)
        {
            if (nullChild)
                return false;

            if (q->left != -1)
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
    if (q->left != -1 && !nullBrother)
    {
        q->next = NULL;
        bfsOrder(nextP, nullChild);
    } else if (q->left == -1)
    {
        return true;
    } else return false;


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
        int leftNode, rightNode;
        cin >> leftNode >> rightNode;
        hasPar[leftNode]++;
        hasPar[rightNode]++;
        tree[i] = new Node(i, leftNode, rightNode);
    }

    int i = 1;
    for (; i <= num; i++)
    {
        if (hasPar[i] == 0)
            break;
    }

    if (bfsOrder(tree[i], false)) cout << 'Y';
    else cout << 'N';

    return 0;
}


