#include <iostream>
#include <fstream>

using namespace std;

int getMin(long long arr[])
{
    long long minNum = 100000000;
    for (int i = 0; i < 3; i++)
    {
        if (minNum > arr[i]) minNum = arr[i];
    }

    for (int i = 0; i < 3; i++)
    {
        if (minNum == arr[i]) return i;
    }
}

int main()
{
    int n = 0;
    int store[100001] = {};

    // ������̨�������ʱ��
    long long num[3] = {0};

    // ������̨���ܴ���ʱ��
    long long total[3] = {0};

    // �˿͵ı��
    long long index[3] = {0};

    long long result = 0;
    long long max = 0;

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> store[i];

    // Old rule
    for (int i = 0; i < n; ++i)
    {
        int tmpIndex = getMin(index);
        num[tmpIndex] += store[i];
        total[tmpIndex] += num[tmpIndex];
        ++index[tmpIndex];
    }

    for (int i = 0; i < 3; i++)
    {
        total[i] -= num[i];
        result += total[i];
    }

    if (num[0] > num[1])
        max = num[0];
    else
        max = num[1];
    if (max < num[2])
        max = num[2];


    cout << result << " " << max << endl;


    // New rule
    // init value
    for (int i = 0; i < 3; i++)
    {
        num[i] = 0;
        total[i] = 0;
    }
    result = 0;
    max = 0;

    // Start
    for (int i = 0; i < n; i++)
    {
        int tmpIndex = getMin(num);
        num[tmpIndex] += store[i];
        total[tmpIndex] += num[tmpIndex];
    }

    for (int i = 0; i < 3; i++)
    {
        total[i] -= num[i];
        result += total[i];
    }

    if (num[0] > num[1])
        max = num[0];
    else
        max = num[1];
    if (max < num[2])
        max = num[2];
    cout << result << " " << max;
    return 0;
}