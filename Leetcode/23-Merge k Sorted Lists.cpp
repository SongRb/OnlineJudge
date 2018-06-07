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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* lpr, ListNode* rpr){return lpr->val>rpr->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        int length = lists.size();
        ListNode* head = new ListNode(0);
        ListNode* p =head;
        for(int i=0;i<length;i++)
        {
            if(lists[i]!=NULL) pq.push(lists[i]);
        }
        // cout<<p->val<<endl;
        while(!pq.empty())
        {
            // cout<<"Hello"<<endl;
            auto q = pq.top();
            // cout<<q->val<<endl;
            pq.pop();
            if(q->next!=NULL) 
            {
                pq.push(q->next);  
            }
            p->next = q;
            p = p->next; 
        }
        return head->next;
    }
};