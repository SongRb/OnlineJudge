#include <iostream>
#include <cstring>

using namespace std;

struct Node
{
    int num = 0;
    Node *next;
    Node *prev;

    Node(int n, Node *ne, Node *pr) : num(n), next(ne), prev(pr)
    {
    }

};


int main()
{
    Node *head = new Node(0, NULL, NULL);

    int numMonkey = 0;
    int numOper = 0;
    cin >> numMonkey >> numOper;

    int total = numMonkey;

    head->next = new Node(1, NULL, NULL);
    Node *p = head->next;


    int totalNum = 1;

    for (int i = 1; i < numMonkey; i++)
    {
        p->next = new Node(i + 1, NULL, p);
        p = p->next;
        totalNum += i + 1;
    }
    Node *tail = p;
    p->next = head->next;
    p->next->prev = p;
    p->prev = tail;
    p = tail;



    // ÿ��ѭ�����������µ��Ǹñ����ĺ��ӵ�ǰһֻ
    for (int i = 0; i < numOper; i++)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int k;
            cin >> k;
            int len = k % total;

            // len =0 Ӧ��Ҫɾ������ڵ�ǰ���Ǹ��ڵ�
            if (len == 0)
            {
                p = p->prev;
            } else
            {
                for (int i = 0; i < len - 1; i++)
                {
                    p = p->next;
                }
            }

            Node *tmp = p->next;
            p->next = p->next->next;
            p->next->prev = p;

            totalNum -= tmp->num;

            delete tmp;
            total--;

        } else if (type == 1)
        {
            int k, w;
            cin >> k >> w;
            int len = k % total;
            for (int i = 0; i < len; i++)
            {
                p = p->next;
            }
            Node *tmp = p->next;
            p->next = new Node(w, tmp, p);
            tmp->prev = p->next;
            total++;
            totalNum += w;
        }
    }

    cout << totalNum;

    return 0;
}

