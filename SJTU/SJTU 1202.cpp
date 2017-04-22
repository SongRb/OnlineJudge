#include <iostream>
#include <cstdio>

using namespace std;

struct Node
{
    int digit = 0;
    Node *next = NULL;
    Node *prev = NULL;
};


int main()
{

    Node *num1 = new Node;
    num1->next = new Node;

    Node *num2 = new Node;
    num2->next = new Node;

    Node *p = num1;

    char c;
    do
    {
        c = getchar();
        if (c != '\n')
        {
            p->next->digit = c - '0';
            p->next->prev = p;
            p->next->next = new Node;
            p = p->next;
        } else
        {
            p->next = NULL;
        }
    } while (c != '\n');

    Node *num1tail = p;

    p = num2;
    do
    {
        c = getchar();
        if (c != '\n')
        {
            p->next->digit = c - '0';
            p->next->prev = p;
            p->next->next = new Node;
            p = p->next;
        } else
        {
            p->next = NULL;
        }
    } while (c != '\n');

    Node *num2tail = p;

    Node *p1 = num1tail;
    Node *p2 = num2tail;

    Node *num3 = new Node;
    num3->next = new Node;
    Node *p3 = num3->next;

    while (p1 && p2)
    {
        p3->next = new Node;
        int tmp = p1->digit + p2->digit;
        p3->digit += tmp;

        if (p3->digit >= 10)
        {
            p3->digit -= 10;
            p3->next->digit += 1;
        }
        p3->next->prev = p3;

        p3 = p3->next;
        p1 = p1->prev;
        p2 = p2->prev;
    }
    Node *tmp = p1 ? p1 : p2;


    while (tmp)
    {
        p3->next = new Node;
        p3->digit += tmp->digit;

        if (p3->digit >= 10)
        {
            p3->digit -= 10;
            p3->next->digit += 1;
        }
        p3->next->prev = p3;
        p3 = p3->next;
        tmp = tmp->prev;
    }
    p3 = p3->prev;
    if (p3->digit == 0)
        p3 = p3->prev;

    while (p3)
    {
        cout << p3->digit;
        p3 = p3->prev;
    }

    return 0;


}
