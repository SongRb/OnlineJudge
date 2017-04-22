#include <cstdio>

using namespace std;

int fruits[10005];

class Heap
{
private:
    long long int size;
    long long int currentSize;
    long long int *tree;

public:
    Heap(long long int s = 20) : size(s)
    {
        tree = new long long int[size];
        currentSize = 0;
    }

    bool lessThan(long long int a, long long int b)
    {
        return a < b;
    }

    void insert(const long long int &x)
    {
        if (currentSize == size)
            doubleSpace();

        long long int hole = ++currentSize;
        long long int copy = x;

        tree[0] = copy;
        for (; x < tree[hole / 2]; hole /= 2)
            tree[hole] = tree[hole / 2];
        tree[hole] = tree[0];

    }

    void doubleSpace()
    {
        long long int *tmpTree = new long long int[size * 2];
        for (long long int i = 0; i <= size; i++)
        {
            tmpTree[i] = tree[i];
        }

        delete tree;
        tree = tmpTree;
        size *= 2;
    }

    void deleteMin()
    {
        if (currentSize == 0)
            return;
        tree[1] = tree[currentSize--];
        percolateDown(1);
    }

    void deleteMin(long long int minTerm)
    {
        if (currentSize == 0)
            return;
        minTerm = tree[1];
        tree[1] = tree[currentSize--];
        percolateDown(1);
    }

    long long int getMin()
    {
        return tree[1];
    }

    void percolateDown(long long int hole)
    {
        long long int child;
        long long int tmp = tree[hole];

        for (; hole * 2 <= currentSize; hole = child)
        {
            child = hole * 2;
            if (child != currentSize && lessThan(tree[child + 1], tree[child]))
                ++child;
            if (lessThan(tree[child], tmp))
                tree[hole] = tree[child];
            else
                break;
        }
        tree[hole] = tmp;
    }

    long long int getNum()
    {
        return currentSize;
    }
};


int main()
{
    int N;
    scanf("%d", &N);
    Heap fruits(10005);
    for (int i = 0; i < N; i++)
    {
        int fruit;
        scanf("%d", &fruit);
        fruits.insert(fruit);
    }

    int result = 0;
    while (fruits.getNum() != 1)
    {
        int tmp = 0;
        for (int j = 0; j < 2; j++)
        {
            tmp += fruits.getMin();
            fruits.deleteMin();
        }
        fruits.insert(tmp);
        result += tmp;
    }
    //result = fruits.getMin();
    printf("%d\n", result);
}