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
    void reorderList(ListNode* head) {
        if(head==NULL) return ;
        vector<ListNode*> vec;
        ListNode* p = head;
        while(p)
        {
            vec.push_back(p);
            p = p->next;
        }
        int startIdx = 0;
        int endIdx = vec.size()-1;
        int lastIdx = 0;
        while(true)
        {
            if(startIdx<endIdx)
            {
                vec[startIdx]->next = vec[endIdx];
                lastIdx = endIdx;
                startIdx++;   
            }
            else
            {
                break;
            }
            if(startIdx<endIdx)
            {
                vec[endIdx]->next = vec[startIdx];
                lastIdx = startIdx;
                endIdx--;   
            }
            else
            {
                break;
            }
        }
        vec[lastIdx]->next = NULL;
        return;
    }
};