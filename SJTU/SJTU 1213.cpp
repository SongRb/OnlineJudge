#include <iostream>

using namespace std;

struct Node
{
    int value;
    int right;
    int left;

    Node(int d, int l = NULL, int r = NULL) : value(d), left(l), right(r)
    {
    }

    Node(const Node *p)
    {
        value = p->value;
        left = p->left;
        right = p->right;
    }
};


Node *tree1[100005];
Node *tree2[100005];

bool checkSame(int p1, int p2)
{
    if (p1 != 0 && p2 != 0)
    {
        return tree1[p1]->value == tree2[p2]->value && checkSame(tree1[p1]->left, tree2[p2]->left) &&
               checkSame(tree1[p1]->right, tree2[p2]->right);
    } else if (p1 == 0 && p2 == 0)
        return true;
    else return false;
}


int hasPar1[100005];
int hasPar2[100005];


int main()
{
    int tree1Size, tree2Size;
    cin >> tree1Size;

    for (int i = 1; i <= tree1Size; i++)
    {
        hasPar1[i] = 0;
    }

    tree1[0] = NULL;
    for (int i = 1; i <= tree1Size; i++)
    {
        int value, leftNode, rightNode;
        cin >> leftNode >> rightNode >> value;
        hasPar1[leftNode]++;
        hasPar1[rightNode]++;
        tree1[i] = new Node(value, leftNode, rightNode);
    }

    int root1 = 1;
    for (; root1 <= tree1Size; root1++)
    {
        if (hasPar1[root1] == 0)
            break;
    }

    cin >> tree2Size;
    if (tree1Size != tree2Size)
    {
        cout << "N" << endl;
        return 0;
    }

    for (int i = 1; i <= tree2Size; i++)
    {
        hasPar2[i] = 0;
    }

    tree2[0] = NULL;
    for (int i = 1; i <= tree2Size; i++)
    {
        int value, leftNode, rightNode;
        cin >> leftNode >> rightNode >> value;
        hasPar2[leftNode]++;
        hasPar2[rightNode]++;
        tree2[i] = new Node(value, leftNode, rightNode);
    }

    int root2 = 1;
    for (; root2 <= tree2Size; root2++)
    {
        if (hasPar2[root2] == 0)
            break;
    }

    bool flag = checkSame(root1, root2);
    if (flag) cout << "Y" << endl;
    else cout << "N" << endl;

    return 0;
}




