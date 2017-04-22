#include <iostream>

using namespace std;

struct compare
{
    bool operator()(const long long int &l, const long long int &r)
    {
        return l > r;
    }
};


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

    void traverse()
    {
        for (long long int i = 1; i <= currentSize; i++)
            cout << tree[i] << " ";
    }

    long long int getNum()
    {
        return currentSize;
    }
};


int main()
{
    long long int M, N;
    cin >> N >> M;

    Heap mypq(200000);


    long long int x = M - 2 - (N - 2) % (M - 1);;
    for (long long int i = 0; i < x; i++)
    {
        mypq.insert(0);
    }

    for (long long int i = 0; i < N; i++)
    {
        long long int v;
        cin >> v;
        mypq.insert(v);
    }

    long long int result = 0;
    while (mypq.getNum() > 1)
    {
        long long int totalV = 0;
        for (long long int i = 0; i < M; i++)
        {
            totalV += mypq.getMin();
            result += mypq.getMin();
            mypq.deleteMin();
        }
        mypq.insert(totalV);
    }
    cout << result << endl;

}