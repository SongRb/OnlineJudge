/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* p = head;
        ListNode* prev = NULL;
        int cnt = 0;
        deque<ListNode*> stk;
        ListNode* newHead = new ListNode(-1);
        prev = newHead;
        while(p)
        {
            stk.push_back(p);
            if(stk.size()==k)
            {
                // cout<<"Je"<<endl;
                ListNode* n = p->next;
                while(!stk.empty())
                {
                    prev->next = stk.back();
                    // cout<<prev->next->val<<endl;
                    stk.pop_back();
                    prev = prev->next;
                }
                prev->next = NULL;
                p = n;
            }
            else
            {
                p = p->next;
            }
        }
        if(!stk.empty()) prev->next = stk.front();
        p = newHead->next;
        // cout<<"pï¼ "<<endl;
        // while(p)
        // {
        //     cout<<p->val<<endl;
        //     p=p->next;
        // }
        return newHead->next;  
    }
};