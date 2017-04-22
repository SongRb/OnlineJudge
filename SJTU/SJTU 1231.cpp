#include <iostream>

using namespace std;

int lChild[100000];
int rChild[100000];
int parent[100000] = {0};

int path[100000];
int pathTop = -1;

int N, X, Y;

int result = 0;

int check(int p)
{
    if (p == X)
        return 1;
    else if (p == Y)
        return -1;
    else if (p == 0)
        return 0;

    if (check(lChild[p]) * check(rChild[p]) == -1)
        result = p;

    if (check(lChild[p]) != 0)
        return check(lChild[p]);

    if (check(rChild[p]) != 0)
        return check(rChild[p]);

    return 0;
}


int main()
{

    cin >> N >> X >> Y;

    for (int i = 1; i <= N; i++)
    {
        cin >> lChild[i] >> rChild[i];
        parent[lChild[i]] = i;
        parent[rChild[i]] = i;
    }

    int root = 1;
    for (int root = 1; root <= N; root++)
    {
        if (parent[root] == 0) break;
    }

    check(root);
    cout << result << endl;
}