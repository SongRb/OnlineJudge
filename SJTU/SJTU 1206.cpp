#include <iostream>
#include <cstring>


using namespace std;

class ExprStackStr
{
private:
    string *data;


public:

    int totalSize;

    ExprStackStr(int init_size) : totalSize(init_size)
    {
        data = new string[totalSize];
    }

    ~ExprStackStr()
    {
        delete[]data;
    }

    int length = 0;

    void push(string input_str)
    {
        if (length == totalSize - 1)
            doubleSize();
        data[length++] = input_str;
    }

    void pop()
    {
        length--;
    }

    void doubleSize()
    {
        string *tmp;
        int ori_size = totalSize;
        tmp = new string[totalSize];
        for (int i = 0; i < totalSize; i++)
            tmp[i] = data[i];

        delete[]data;
        totalSize *= 2;

        data = new string[totalSize];
        for (int i = 0; i < ori_size; i++)
            data[i] = tmp[i];

        delete[]tmp;
    }

    string top()
    {
        return data[length - 1];
    }

    string secTop()
    {
        return data[length - 2];
    }

    void traverse()
    {
        for (int i = 0; i < length; i++)
            cout << data[i] << endl;
    }

};


int main()
{
    ExprStackStr Anal(20);
    string tmp;

    while (cin >> tmp)
    {
        if (tmp == "then")
        {
            if (Anal.top() == "if" || Anal.top() == "elif")
                Anal.push(tmp);
            else
            {
                cout << "Error!" << endl;
                return 0;
            }
        } else if (tmp == "if")
        {
            if (Anal.length != 0)
            {
                if (Anal.top() == "if")
                {
                    cout << "Error!" << endl;
                    return 0;
                } else if (Anal.top() == "else")
                {
                    Anal.pop();
                    Anal.push("elif");
                    continue;
                }
            }

            Anal.push(tmp);
        } else if (tmp == "begin")
        {
            if (Anal.length != 0 && (Anal.top() == "if" || Anal.top() == "elif"))
            {
                cout << "Error!" << endl;
                return 0;
            }
            Anal.push(tmp);
        } else if (tmp == "end")
        {
            while (Anal.length != 0 && Anal.top() == "then" && (Anal.secTop() == "if" || Anal.secTop() == "elif"))
            {
                Anal.pop();
                Anal.pop();
            }

            if (Anal.length != 0 && Anal.top() == "begin")
            {
                Anal.pop();
            } else
            {
                cout << "Error!" << endl;
                return 0;
            }
        } else if (tmp == "else")
        {
            if (Anal.length != 0 && Anal.top() == "then" && (Anal.secTop() == "if" || Anal.secTop() == "elif"))
            {
                Anal.pop();
                Anal.pop();
            } else
            {
                cout << "Error!" << endl;
                return 0;
            }
        }
    }

    if (Anal.length == 0)
        cout << "Match!" << endl;
    else
        cout << "Error!" << endl;
}