package L000;

import util.ListNode;

public class LeetCode0082 {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode dummp = new ListNode(0);
        ListNode t = dummp;
        while (head != null && head.next != null) {
            if (head.next.val != head.val) {
                t.next = head;
                head = head.next;
                t = t.next;
                t.next = null;
            } else {
                int val = head.val;
                while (head != null && head.val == val) {
                    head = head.next;
                }
            }
        }
        if (head != null) {
            t.next = head;
        }
        return dummp.next;
    }
}
