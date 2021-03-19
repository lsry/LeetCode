package L000;

import util.ListNode;

public class LeetCode0092 {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        int index = 0;
        ListNode h = new ListNode(0);
        ListNode t = h, th = h;
        while (head != null) {
            ListNode cur = head;
            head = head.next;
            cur.next = null;
            ++index;
            if (index < left || index > right) {
                t.next = cur;
                t = cur;
                th = t;
            } else {
                if (index == left) {
                    t = cur;
                }
                cur.next = th.next;
                th.next = cur;
            }
        }
        return h.next;
    }
}
