#include <iostream>

using namespace std;

int dataSet[1001], length = 0;
int tmpSet[1001];

void sort(int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = dataSet[(left + right) / 2];

    /* partition */
    while (i <= j)
    {
        while (dataSet[i] < pivot)
            i++;
        while (dataSet[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = dataSet[i];
            dataSet[i] = dataSet[j];
            dataSet[j] = tmp;
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


bool find(int q, int re[], int bound)
{
    for (int i = 1; i <= bound; i++)
    {
        if (re[i] == q)
            return true;
    }
    return false;
}

void display()
{
    sort(1, length);
    for (int i = 1; i <= length; i++)
    {
        cout << dataSet[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int N, m, d = 0, tmpLength;
    cin >> N;
    char command;
    for (int i = 1; i <= N; ++i)
    {
        cin >> command;
        if (command == '+')
        {
            cin >> m;
            for (int j = 1; j <= m; ++j)
            {
                cin >> d;
                if (!find(d, dataSet, length))
                {
                    ++length;
                    dataSet[length] = d;
                }
            }
        } else if (command == '-')
        {
            tmpLength = length;
            length = 0;
            cin >> m;
            for (int j = 1; j <= m; j++)
            {
                cin >> tmpSet[j];
            }
            for (int j = 1; j <= tmpLength; j++)
            {
                if (!find(dataSet[j], tmpSet, m))
                {
                    dataSet[++length] = dataSet[j];
                }
            }
        } else if (command == '*')
        {
            cin >> m;
            tmpLength = length;
            length = 0;
            for (int j = 0; j < m; j++)
            {
                cin >> d;
                if (find(d, dataSet, tmpLength))
                {
                    tmpSet[++length] = d;
                }
            }

            for (int j = 1; j <= length; j++)
            {
                dataSet[j] = tmpSet[j];
            }
        }
        display();
    }


    return 0;
}

