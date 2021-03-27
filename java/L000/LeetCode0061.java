package L000;

import util.ListNode;

public class LeetCode0061 {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return head;
        }
        int n = 0;
        ListNode t = head;
        while (t != null) {
            ++n;
            t = t.next;
        }
        k = k % n;
        if (k == 0) {
            return head;
        }
        t = head;
        for (int i = 0;i < n - k - 1;++i) {
            t = t.next;
        }
        ListNode nh = t.next;
        t.next = null;
        t = nh;
        while (t.next != null) {
            t = t.next;
        }
        t.next = head;
        return nh;
    }
}
