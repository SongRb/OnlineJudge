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

class BinaryTree
{
private:
    Node *tree[100005];
    int hasPar[100005];
    int totalNum;

    void bfsOrder(Node *floor)
    {
        Node *nextP = new Node(0, -1, 0);
        if (!floor) return;
        Node *p = floor;
        Node *q = nextP;
        do
        {
            cout << p->value << ' ';
            if (p->left)
            {
                if (q->left != -1)
                {
                    q->next = tree[p->left];
                    q = q->next;
                } else
                {
                    nextP = tree[p->left];
                    q = nextP;
                }
            }
            if (p->right)
            {
                if (q->left != -1)
                {
                    q->next = tree[p->right];
                    q = q->next;
                } else
                {
                    nextP = tree[p->right];
                    q = nextP;
                }
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


public:
    BinaryTree(int n) : totalNum(n)
    {
        for (int i = 1; i <= totalNum; i++)
        {
            hasPar[i] = 0;
        }
        tree[0] = NULL;
    }

    ~BinaryTree()
    {
    }

    void addNode(int num, int value, int left, int right)
    {
        hasPar[left]++;
        hasPar[right]++;
        tree[num] = new Node(value, left, right);
    }

    void bfsTrav()
    {
        int i = 1;
        for (; i <= totalNum; i++)
        {
            if (hasPar[i] == 0)
                break;
        }

        bfsOrder(tree[i]);
    }


};


int main()
{
    int num;
    cin >> num;

    BinaryTree hh(num);

    for (int i = 1; i <= num; i++)
    {
        int leftNode, rightNode, value;
        cin >> leftNode >> rightNode >> value;
        hh.addNode(i, value, leftNode, rightNode);
    }

    hh.bfsTrav();
    return 0;
}