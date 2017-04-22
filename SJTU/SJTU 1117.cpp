#include <cstdio>

using namespace std;

// parent index of index
int parent[100000];
int connectedNodeNum[100000];


int stack[100000];
int stackTop = 0;


int main()
{
    char ch;
    int nodeNum = 1;
    int node, brackets = 1;
    scanf(" %c%d", &ch, &node);
    stack[stackTop++] = node;
    while (brackets)
    {
        scanf(" %c", &ch);
        if (ch == '(')
        {
            brackets++;

            scanf("%d", &node);
            nodeNum++;
            parent[node] = stack[stackTop - 1];
            connectedNodeNum[stack[stackTop - 1]]++;
            connectedNodeNum[node] = 1;
            stack[stackTop++] = node;
        } else
        {
            brackets--;
            stack[--stackTop];

        }
    }

    for (int i = 1; i <= nodeNum; i++)
    {
        int k = i;
        int linked_node;
        // k<=i
        //
        while (connectedNodeNum[k] == 1 && k <= i)
        {
            // k是最小的叶节点
            connectedNodeNum[k]--;

            // k的父节点存在且与其相连
            if (parent[k] && connectedNodeNum[parent[k]] > 0)
            {
                linked_node = parent[k];
            } else
                // 找到以k为父节点的节点
            {
                for (int j = 1; j <= nodeNum; j++)
                    if (parent[j] == k && connectedNodeNum[j] > 0)
                    {
                        linked_node = j;
                        break;
                    }
            }
            printf("%d ", linked_node);
            connectedNodeNum[linked_node]--;
            k = linked_node;
        }
    }
    return 0;
}
