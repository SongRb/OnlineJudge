#include <iostream>
#include <cstring>

// û�����κ��Ż��Ĵ��룬����������

using namespace std;

char ac[303];
char bc[303];

int a[303];
int b[303];


int result[606];
int tmpResult[304];


int main()
{
    cin >> ac >> bc;

    int tmpResultSize = 304;
    int resultSize = 606;

    int lengthA = strlen(ac);
    int lengthB = strlen(bc);

    tmpResult[0] = 0;

    for (int i = 0; i < lengthA; i++)
    {
        a[i] = ac[i] - '0';
    }

    for (int i = 0; i < lengthB; i++)
    {
        b[i] = bc[i] - '0';
    }

    for (int i = 0; i < resultSize; i++)
    {
        result[i] = -1;
    }

    for (int i = 0; i < tmpResultSize; i++)
    {
        tmpResult[i] = 0;
    }

    int tmpDigit = 0;
    int tmpCarry = 0;

    for (int i = lengthB - 1; i >= 0; i--)
    {
        int index = 0; //index that stores in tmpResult
        for (int j = lengthA - 1; j >= 0; j--)
        {
            tmpDigit = (a[j]) * b[i] + tmpCarry;
            tmpCarry = 0;
            while (tmpDigit >= 10)
            {
                tmpCarry++;
                tmpDigit -= 10;
            }

            index = j + tmpResultSize - lengthA;
            tmpResult[index] = tmpDigit;
            if (j == 0)
            {
                tmpResult[index - 1] = tmpCarry;
            }
        }


        tmpCarry = 0;
        tmpDigit = 0;

        for (int k = tmpResultSize - 1; k >= index - 1; k--)
        {
            int resIndex = resultSize - (tmpResultSize - 1 - k + (lengthB - i));

            if (result[resIndex] == -1) result[resIndex] = 0;

            tmpDigit = tmpCarry + result[resIndex] + tmpResult[k];
            if (tmpDigit >= 10)
            {
                tmpDigit -= 10;
                tmpCarry = 1;
            } else
            {
                tmpCarry = 0;
            }
            result[resIndex] = tmpDigit;
        }

        tmpCarry = 0;
        tmpDigit = 0;
    }

    for (int i = 0; i < resultSize; i++)
    {
        if (result[i] == -1) continue;
        if (result[i] == 0 && (result[i - 1] == -1)) continue;
        cout << result[i];
    }
    cout << endl;

    return 0;
}


