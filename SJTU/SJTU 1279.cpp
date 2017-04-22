#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int numParser(char ch)
{
    if (ch >= 'A' && ch <= 'C')
        return 2;
    else if (ch >= 'D' && ch <= 'F')
        return 3;
    else if (ch >= 'G' && ch <= 'I')
        return 4;
    else if (ch >= 'J' && ch <= 'L')
        return 5;
    else if (ch >= 'M' && ch <= 'O')
        return 6;
    else if (ch >= 'P' && ch <= 'S')
        return 7;
    else if (ch >= 'T' && ch <= 'V')
        return 8;
    else if (ch >= 'W' && ch <= 'Y')
        return 9;
    else if (ch >= '0' && ch <= '9')
        return ch - '0';

}

int phoneNum[10000000] = {0};

int main()
{
    int N;

    bool dupFlag = false;

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        char input[3000];
        cin >> input;

        int num = 0;

        for (int j = 0; j < strlen(input); ++j)
        {
            if (input[j] == '-')
                continue;
            num = num * 10 + (numParser(input[j]));
        }
        if (phoneNum[num] >= 1)
            dupFlag = true;

        ++phoneNum[num];
    }
    if (!dupFlag)
    {
        cout << "No duplicates." << endl;
        return 0;
    }

    for (int i = 1; i <= 9999999; ++i)
    {
        if (phoneNum[i] > 1)
        {
            printf("%03d-", i / 10000);
            printf("%04d ", i % 10000);
            printf("%d\n", phoneNum[i]);
        }
    }
    return 0;
}
