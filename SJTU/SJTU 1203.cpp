#include <iostream>

using namespace std;

template<typename T>
void sol(T var, int n, int m);

template<class elemType>
class List
{
public:
    List(int cap) : capacity(cap), currentLength(0)
    {
        data = new elemType[cap];
    }

    ~List()
    {
        delete[]data;
    }


    List(const List<elemType> &lst)
    {
        if (&lst != this)
        {
            capacity = lst.getCapacity();
            delete[]data;
            data = new elemType[capacity];
            for (int i = 0; i < lst.getLength(); i++)
            {
                data[i] = lst.data[i];
            }
            currentLength = lst.getLength();
        }

    }

    List<elemType> operator=(const List<elemType> &lst)
    {
        if (lst != this)
        {
            capacity = lst.getCapacity();
            delete[]data;
            data = new elemType[capacity];
            for (int i = 0; i < lst.getLength(); i++)
            {
                data[i] = lst.data[i];
            }
            currentLength = lst.getLength();
        }
        return *this;
    }

    void append(const elemType &x)
    {
        data[currentLength++] = x;
    }

    List<elemType> operator+(List<elemType> &lst)
    {
        List<elemType> newList(capacity + lst.getCapacity());
        for (int i = 0; i < capacity; i++)
        {
            newList.append(data[i]);
        }

        for (int i = 0; i < lst.getCapacity(); i++)
        {
            newList.append(lst.visit(i));
        }

        return newList;
    }

    elemType visit(int i) const
    {
        return data[i];
    }

    int getCapacity() const
    {
        return capacity;
    }

    int getLength() const
    {
        return currentLength;
    }

    void traverse()
    {
        for (int i = 0; i < currentLength; i++)
        {
            cout << data[i] << ' ';
        }
        cout << endl;
    }


private:
    int capacity;
    int currentLength;
    elemType *data;

};

int main()
{

    int n = 0, m = 0;
    char typeCom[8];
    cin >> typeCom;
    cin >> n >> m;


    if (typeCom[0] == 'i')
    {
        int i = 0;
        sol(i, n, m);
    } else if (typeCom[0] == 'c')
    {
        char i = '1';
        sol(i, n, m);
    } else
    {
        double i = 1.0;
        sol(i, n, m);
    }

    return 0;
}

template<typename T>
void sol(T var, int n, int m)
{
    List<T> test1(n);
    List<T> test2(m);

    T tmp;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        test1.append(tmp);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        test2.append(tmp);
    }

    List<T> test3 = test1 + test2;

    test3.traverse();
}
