#include <iostream>

using namespace std;

class PriorityQueue
{
private:
    int tree[20005];
    int dataTop;

public:
    PriorityQueue()
    {
        dataTop = 0;
    }

    ~PriorityQueue() {}

    void push(int d)
    {
        int i = ++dataTop;
        for (; i > 1 && d < tree[i / 2]; i /= 2)
        {
            tree[i] = tree[i / 2];
        }
        tree[i] = d;
    }

    int getMin()
    {
        return tree[1];
    }

    int find(int q)
    {
        int min = 100000000;
        int minIndex = -1;
        for (int i = 1; i <= dataTop; i++)
        {
            if (tree[i] > q && tree[i] < min)
            {
                min = tree[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    void decrease(int i, int v)
    {
        tree[i] -= v;

        for (; i > 1 && tree[i] < tree[i / 2]; i /= 2)
        {
            int tmp = tree[i];
            tree[i] = tree[i / 2];
            tree[i / 2] = tmp;
        }


    }
};

int main()
{
    int M;
    cin >> M;

    PriorityQueue test;
    for (int i = 0; i < M; i++)
    {
        char command[10];
        cin >> command;
        if (command[0] == 'i')
        {
            int d;
            cin >> d;
            test.push(d);
        } else if (command[0] == 'f')
        {
            int d;
            cin >> d;
            cout << test.find(d) << endl;
        } else
        {
            int i, v;
            cin >> i >> v;
            test.decrease(i, v);
        }
    }

    //system("pause");
}