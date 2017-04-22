#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin >> n;
    int tmp1 = 1;
    int tmp2 = 1;
    int result;
    int T = 2;
    while (true)
    {
        result = tmp2 + tmp1;
        tmp1 = tmp2;
        tmp2 = result;
        T++;

        while (tmp1 > 2010)
            tmp1 -= 2010;
        while (tmp2 > 2010)
            tmp2 -= 2010;

        if (tmp1 == 1 && tmp2 == 1)
        {
            T -= 2;
            break;
        }
    }

    tmp1 = 1;
    tmp2 = 1;
    int k = n % T; //Changed
    if (k == 1 || k == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 3; i <= k; ++i)
    {
        result = tmp2 + tmp1;
        tmp1 = tmp2;
        tmp2 = result;
        while (tmp1 > 2010)
            tmp1 -= 2010;
        while (tmp2 > 2010)
            tmp2 -= 2010;

        while (result > 2010)
            result -= 2010;
    }
    cout << result << endl;
    return 0;
}


