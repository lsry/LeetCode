package L100;

import util.ListNode;

public class LeetCode0148 {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode h1 = head;
        ListNode h2 = head.next;
        while (h2 != null && h2.next != null) {
            h1 = h1.next;
            h2 = h2.next.next;
        }
        h2 = h1.next;
        h1.next = null;
        ListNode h11 = sortList(head);
        ListNode h22 = sortList(h2);
        ListNode h0 = new ListNode(0);
        ListNode tail = h0;
        while (h11 != null || h22 != null) {
            if (h11 == null) {
                tail.next = h22;
                break;
            } else if (h22 == null) {
                tail.next = h11;
                break;
            } else {
                if (h11.val <= h22.val) {
                    tail.next = h11;
                    h11 = h11.next;
                } else {
                    tail.next = h22;
                    h22 = h22.next;
                }
                tail = tail.next;
            }
        }
        return h0.next;
    }
}
