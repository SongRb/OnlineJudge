#include <iostream>
#include <cstring>

using namespace std;

template<class elemType>
class Stack
{
public:
    virtual bool isEmpty() const = 0;

    virtual void push(const elemType &x) = 0;

    virtual elemType pop() = 0;

    virtual elemType top() = 0;

    virtual ~Stack() {}
};


template<class elemType>
class seqStack
{
private:
    elemType *elem;
    int top_p;
    int maxSize;

    void doubleSpace()
    {
        elemType *tmp = elem;
        elem = new elemType[2 * maxSize];

        for (int i = 0; i < maxSize; i++)
        {
            elem[i] = tmp[i];
        }

        maxSize *= 2;
        delete[] tmp;
    }

public:
    seqStack(int initSize = 10)
    {
        elem = new elemType[initSize];
        maxSize = initSize;
        top_p = -1;
    }

    ~seqStack()
    {
        delete[] elem;
    }

    bool isEmpty() const
    {
        return top_p == -1;
    }

    void push(const elemType &x)
    {
        if (top_p == maxSize - 1) doubleSpace();
        elem[++top_p] = x;
    }

    elemType pop()
    {
        return elem[top_p--];
    }

    elemType top() const
    {
        return elem[top_p];
    }


};


int main()
{
    char input[110];
    char result[110];

    cin.getline(input, 110);

    int length = strlen(input);

    seqStack<char> test(100);
    seqStack<char> test2(100);

    for (int i = 0; i < length; i++)
    {
        result[i] = ' ';
    }

    for (int i = 0; i < length; i++)
    {
        if (input[i] == '(')
        {
            test.push('(');
        } else if (input[i] == ')')
        {
            if (test.isEmpty())
                result[i] = '?';
            else
            {
                test.pop();
            }
        }
    }

    for (int i = length - 1; i >= 0; i--)
    {
        if (input[i] == ')')
        {
            test2.push(')');
        } else if (input[i] == '(')
        {
            if (test2.isEmpty())
                result[i] = '$';
            else
            {
                test2.pop();
            }
        }
    }

    cout << input << endl;

    for (int i = 0; i < length; i++)
    {
        cout << result[i];
    }

    return 0;
}


