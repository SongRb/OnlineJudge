/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode p = head;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode prev = dummy;
        while(p!=null)
        {
            if(p.val==val) prev.next = p.next;
            else prev = prev.next;
            p = p.next;
        }
        return dummy.next;
    }
}