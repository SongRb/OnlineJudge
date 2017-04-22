#include <iostream>

using namespace std;

int index[50000];
int height[50000];


void sort(int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = height[(left + right) / 2];

    /* partition */
    while (i <= j)
    {
        while (height[i] < pivot)
            i++;
        while (height[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = height[i];
            height[i] = height[j];
            height[j] = tmp;

            tmp = index[i];
            index[i] = index[j];
            index[j] = tmp;


            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        sort(left, j);
    if (i < right)
        sort(i, right);
};


int main()
{
    int N, D;
    cin >> N >> D;

    for (int i = 0; i < N; i++)
    {
        cin >> index[i] >> height[i];
    }

    sort(0, N - 1);

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        bool hasLeft = false, hasRight = false;

        int left = i, right = N - 1;

        int pivot = (left + right) / 2;
        while (2 * height[i] > height[pivot])
        {
            left = pivot;
            pivot = (left + right) / 2;
            if (left == pivot)
            {
                pivot = right;
                break;
            }
        }

        for (int k = pivot; k > i && height[k] >= 2 * height[i]; k--)
        {
            if (2 * height[i] <= height[k])
            {
                if (index[k] - index[i] <= D && index[k] - index[i] > 0) hasLeft = true;

                if (index[k] - index[i] >= -D && index[k] - index[i] < 0) hasRight = true;

                if (hasLeft && hasRight)
                {
                    cnt++;
                    break;
                }
            }
        }

        if (!(hasLeft && hasRight))
        {
            for (int k = pivot + 1; k < N; k++)
            {
                if (2 * height[i] <= height[k])
                {
                    if (index[k] - index[i] <= D && index[k] - index[i] > 0) hasLeft = true;

                    if (index[k] - index[i] >= -D && index[k] - index[i] < 0) hasRight = true;

                    if (hasLeft && hasRight)
                    {
                        cnt++;
                        break;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

