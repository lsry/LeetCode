package L000;

import util.ListNode;

public class LeetCode0086 {
    public ListNode partition(ListNode head, int x) {
        ListNode h1 = new ListNode(0);
        ListNode h2 = new ListNode(0);
        ListNode t1 = h1, t2 = h2;
        while (head != null) {
            ListNode tmp = head;
            head = head.next;
            if (tmp.val < x) {
                t1.next = tmp;
                t1 = t1.next;
                t1.next = null;
            } else {
                t2.next = tmp;
                t2 = t2.next;
                t2.next = null;
            }
        }
        t1.next = h2.next;
        return h1.next;
    }
}
