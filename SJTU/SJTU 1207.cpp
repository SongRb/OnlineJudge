#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int time)
    {
        data = time;
        next = NULL;
    }
};

class Queue
{
public:
    Queue() : length(0)
    {
        head = new Node(-1);
        tail = head;
    }

    ~Queue()
    {
        delete head;
    }

    int top()
    {
        return head->next->data;
    }

    void pop()
    {
        Node *tmp = head->next;
        head->next = head->next->next;
        delete tmp;
        length--;
    }

    void push(int time)
    {
        tail->next = new Node(time);
        tail = tail->next;
        length++;
    }

    int getLength()
    {
        return length;
    }

private:
    int length;
    Node *head;
    Node *tail;
};

int main()
{
    Queue Ferry[2];
    int totalNum = 0;

    cin >> totalNum;

    int inType = 0, inTime = 0;
    for (int i = 0; i < totalNum; i++)
    {
        cin >> inType >> inTime;
        Ferry[inType].push(inTime);
    }

    int nowTime = 0;
    double carTime = 0, truckTime = 0;
    int carNum = Ferry[0].getLength(), truckNum = Ferry[1].getLength();

    for (int i = 0; Ferry[0].getLength() != 0 || Ferry[1].getLength() != 0; i++)
    {
        nowTime = i * 10;
        for (int j = 0; j < 2; j++)
        {
            int cnt = 0;
            while (Ferry[0].getLength() != 0 && Ferry[0].top() <= nowTime && cnt < 4)
            {
                carTime += nowTime - Ferry[0].top();
                Ferry[0].pop();
                cnt++;
            }
            for (int k = 0; k < 5 - cnt; k++)
            {
                if (Ferry[1].getLength() != 0 && Ferry[1].top() <= nowTime)
                {
                    truckTime += nowTime - Ferry[1].top();
                    Ferry[1].pop();
                }
            }
        }
    }


    printf("%.3f %.3f", carTime / carNum, truckTime / truckNum);
    return 0;

}