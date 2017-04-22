#include <iostream>
#include <cstring>

using namespace std;

char tree[1020];


// rIndex: index of root element in tree array
void findSubTree(char *preOrderTree, char *inOrderTree, int rIndex)
{
    int length = strlen(preOrderTree);
    int rootIndex = 0;
    for (; rootIndex < length; rootIndex++)
    {
        if (inOrderTree[rootIndex] == preOrderTree[0]) break;
    }

    tree[rIndex] = preOrderTree[0];

    if (length == 1)
    {
        return;
    }

    char leftInOrderTree[26];

    int leftPreOrderTreeTop = -1;
    char leftPreOrderTree[26];

    char rightInOrderTree[26];

    int rightPreOrderTreeTop = -1;
    char rightPreOrderTree[26];

    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (inOrderTree[j] == preOrderTree[i])
            {
                if (j < rootIndex)
                    leftPreOrderTree[++leftPreOrderTreeTop] = inOrderTree[j];
                else if (j > rootIndex)
                    rightPreOrderTree[++rightPreOrderTreeTop] = inOrderTree[j];
            }
        }
    }
    leftPreOrderTree[++leftPreOrderTreeTop] = '\0';
    rightPreOrderTree[++rightPreOrderTreeTop] = '\0';

    int i = 0;
    for (; i < rootIndex; i++)
    {
        leftInOrderTree[i] = inOrderTree[i];
    }
    leftInOrderTree[i] = '\0';

    i = rootIndex + 1;
    for (; i < length; i++)
    {
        rightInOrderTree[i - rootIndex - 1] = inOrderTree[i];
    }
    rightInOrderTree[i - rootIndex - 1] = '\0';

    if (rootIndex > 0)
    {
        findSubTree(leftPreOrderTree, leftInOrderTree, 2 * rIndex);
    }

    if (rootIndex < length - 1)
    {
        findSubTree(rightPreOrderTree, rightInOrderTree, 2 * rIndex + 1);
    }
}

int main()
{
    char preOrderTree[26];
    char inOrderTree[26];

    for (int i = 0; i < 1020; i++)
        tree[i] = '\0';
    cin >> preOrderTree >> inOrderTree;
    int nodeNum = strlen(inOrderTree);
    findSubTree(preOrderTree, inOrderTree, 1);
    for (int i = 1; i < 1020 && nodeNum != 0; i++)
    {
        if (tree[i] == '\0')
        {
            cout << "NULL";
        } else
        {
            cout << tree[i];
            nodeNum--;
        }
        cout << " ";
    }
    //system("pause");
}