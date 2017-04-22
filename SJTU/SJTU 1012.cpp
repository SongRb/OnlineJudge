#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool test(int, int);

int main()
{
    int S, T;
    cin >> S >> T;
    int **data = new int[T - S + 1];
    for (int i = S; i < T; i++)
    {
        data[i - S] = new int[T - i];
        for (int j = i; j < T; j++)
        {
            data[i - S][j - i] = test(j, i);
        }
    }

    return 0;
}

bool test(int m, int n)
{
    int tmp = ((m % n) * 100) % n;

    if (tmp) return false;
    else return true;
}
