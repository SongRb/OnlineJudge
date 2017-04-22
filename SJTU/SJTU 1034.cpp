#include <iostream>
#include <cstdio>

using namespace std;

class monoQueue
{
    int *data;
    int front;
    int rear;
    int maxSize;

public:
    monoQueue(int initSize = 10) : front(0), rear(0), maxSize(initSize)
    {
        data = new int[maxSize];
    }

    ~monoQueue() { delete[] data; }


    // Insertion
    //
    void enQueue(int x)
    {
        while (rear != front && data[(rear - 1) % maxSize] < x)
        {
            rear = (rear - 1) % maxSize;
        }
        data[rear] = x;
        rear = (rear + 1) % maxSize;
    }

    void deQueue(int x)
    {
        if (data[front] == x)
        {
            front = (front + 1) % maxSize;
        }
    }

    bool empty()
    {
        return front == rear;
    }

    int head() { return data[front]; }
};


// From http://www.cnblogs.com/xiaodd/p/4266547.html
int main()
{
    monoQueue que(200000);

    int N, K;
    cin >> N >> K;
    int *value = new int[N];

    // Huge integer array
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &value[i]);
    }

    int minValue;
    // Insert first K elements into the queue
    for (int i = 0; i < K; ++i)
    {
        que.enQueue(value[i]);
    }

    minValue = que.head();
    if (N == K)
    {
        cout << minValue << endl;
        return 0;
    }
    int p = K;
    while (p != K - 1)
    {
        // deQueue not contained one
        if (p - K < 0)
        {
            que.deQueue(value[p - K + N]);
        } else
        {
            que.deQueue(value[p - K]);
        }

        // enQueue next element
        que.enQueue(value[p]);
        if (minValue > que.head())
        {
            minValue = que.head();
        }

        // If reach the end, restart.
        p = ((p + 1 == N) ? (0) : (p + 1));
    }

    cout << minValue << endl;
    return 0;
}
