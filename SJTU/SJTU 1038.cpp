#include <iostream>

using namespace std;

struct Node
{
    int num = 0;
    Node *next;

    Node(int n, Node *p) : num(n), next(p)
    {
    }

};


int main()
{

    int killNum[10000];


    Node *head = new Node(0, NULL);

    int numMonkey = 0;
    cin >> numMonkey;

    head->next = new Node(1, NULL);
    Node *p = head->next;

    int killNumIndex = 0;
    for (int i = 0; i < numMonkey - 1; i++)
    {
        cin >> killNum[i];
    }

    for (int i = 0; i < numMonkey - 1; i++)
    {
        killNum[i] = killNum[i] % (numMonkey - i);
        if (killNum[i] == 0)
            killNum[i] = numMonkey - i;
    }


    for (int i = 1; i < numMonkey; i++)
    {
        p->next = new Node(i + 1, NULL);
        p = p->next;
    }
    Node *tail = p;
    p->next = head->next;

    p = tail;


    int cnt = 0;

    Node *tmp;
    for (int i = 0; i < numMonkey - 1; ++i)
    {
        for (int j = 0; j < killNum[i] - 1; ++j)
        {
            p = p->next;
        }
        tmp = p->next;
        p->next = tmp->next;
        delete tmp;
    }
    cout << p->num;

    return 0;
}
