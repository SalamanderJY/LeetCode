/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy;
        while (pre.next != null && pre.next.next != null) {
            ListNode temp1 = pre.next;
            ListNode temp2 = pre.next.next;
            pre.next = temp2;
            temp1.next = temp2.next;
            temp2.next = temp1;
            pre = pre.next.next;
        }
        return dummy.next;
    }
}