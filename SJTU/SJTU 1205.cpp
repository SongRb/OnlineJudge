#include <iostream>

using namespace std;

int ackFuncPri(int, int);

int main()
{
    int x = 0, y = 0;
    cin >> x >> y;
    cout << ackFuncPri(x, y) << endl;
    return 0;
}

int ackFuncPri(int x, int y)
{
    if (x == 0)
    {
        return y + 1;
    }
    if (y == 0)
    {
        return ackFuncPri(x - 1, 1);
    }
    return ackFuncPri(x - 1, ackFuncPri(x, y - 1));

}

