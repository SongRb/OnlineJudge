#include <iostream>
#include <cstring>

using namespace std;

int main()
{

    char *article[100];
    for (int i = 0; i < 100; i++)
        article[i] = new char[2000];
    int par_num = 0;

    char tmpInput[2000];

    while (true)
    {
        cin.getline(article[par_num++], 2000, '\n');
        if (!strcmp(article[par_num - 1], "******"))
            break;
    }
    par_num--;

    char *tmpCommand = new char[5];

    while (true)
    {
        cin >> tmpCommand;
        if (tmpCommand[0] == 'l')
        {
            int sIndex = 0, eIndex = 0;
            cin >> sIndex >> eIndex;
            if (sIndex < 1 || sIndex > par_num || eIndex < 1 || eIndex > par_num || sIndex > eIndex)
            {
                cout << "Error!" << endl;
                continue;
            }
            for (int i = sIndex - 1; i < eIndex; i++)
            {
                cout << article[i] << endl;
            }
        } else if (tmpCommand[0] == 'i')
        {
            // sIndex is the number of character to be moved
            int lIndex = 0, sIndex = 0;
            cin >> lIndex >> sIndex;
            char *tmpIn = new char[101];
            char tmp;
            cin.get(tmp);
            cin.getline(tmpIn, 101);
            if (lIndex < 1 || lIndex > par_num)
            {
                cout << "Error!" << endl;
                continue;
            }

            int parLength = strlen(article[lIndex - 1]);

            int inputLength = strlen(tmpIn);

            if (sIndex < 1 || sIndex > parLength + 1)
            {
                cout << "Error!" << endl;
                continue;
            }

            for (int i = parLength - 1; i >= sIndex - 1; i--)
            {
                article[lIndex - 1][i + inputLength] = article[lIndex - 1][i];
            }
            parLength += inputLength;
            article[lIndex - 1][parLength] = '\0';


            for (int i = 0; i < inputLength; i++)
            {
                article[lIndex - 1][i + sIndex - 1] = tmpIn[i];
            }

        } else if (tmpCommand[0] == 'd')
        {
            unsigned int lIndex = 0, sIndex = 0, delLength = 0;
            cin >> lIndex >> sIndex >> delLength;

            if (lIndex < 1 || lIndex > par_num || sIndex < 1 || sIndex + delLength - 1 > strlen(article[lIndex - 1]))
            {
                cout << "Error!" << endl;
                continue;
            }

            int lineLength = strlen(article[lIndex - 1]);

            for (int i = 0; i < lineLength - delLength - sIndex + 1; i++)
            {
                article[lIndex - 1][i + sIndex - 1] = article[lIndex - 1][i + delLength + sIndex - 1];
            }

            for (int i = 0; i < delLength; i++)
            {
                article[lIndex - 1][lineLength - 1 - i] = NULL;
            }

            article[lIndex - 1][lineLength - delLength] = '\0';
        } else if (tmpCommand[0] == 'q')
        {
            for (int i = 0; i < par_num; i++)
                cout << article[i] << endl;
            break;
        }
    }

    return 0;
}

