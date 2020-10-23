package L100;

import util.ListNode;

public class LeetCode0143 {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return;
        }
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode ho = new ListNode(0);
        fast = slow.next;
        slow.next = null;
        while (fast != null) {
            ListNode t = fast.next;
            fast.next = ho.next;
            ho.next = fast;
            fast = t;
        }
        slow = head;
        ho = ho.next;
        while (slow != null && ho != null) {
            ListNode t1 = slow.next;
            ListNode t2 = ho.next;
            ho.next = slow.next;
            slow.next = ho;
            slow = t1;
            ho = t2;
        }
    }
}
