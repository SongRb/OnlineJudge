#include <iostream>
#include <fstream>

using namespace std;


void sort(int num[], int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = num[(left + right) / 2];

    /* partition */
    while (i <= j)
    {
        while (num[i] < pivot)
            i++;
        while (num[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = num[i];
            num[i] = num[j];
            num[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        sort(num, left, j);
    if (i < right)
        sort(num, i, right);
};

int main()
{
    int numbers[1000];
    bool have[1000] = {0};
    int top = -1;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        numbers[++top] = k;
        have[k] = true;
    }


    while (true)
    {
        sort(numbers, 0, top);
        bool addFlag = false;
        int n = top;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int res = numbers[i] / numbers[j];
                if (!have[res])
                {
                    numbers[++top] = res;
                    have[res] = true;
                    addFlag = true;
                }
            }
        }
        if (!addFlag) break;

    }

    cout << top + 1 << endl;
    return 0;
}

