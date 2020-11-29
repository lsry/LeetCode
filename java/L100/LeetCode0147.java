package L100;

import util.ListNode;

public class LeetCode0147 {
    public ListNode insertionSortList(ListNode head) {
        ListNode root = new ListNode(0);
        while (head != null) {
            ListNode node = head;
            head = head.next;
            ListNode r = root;
            while (r.next != null && r.next.val <= node.val) {
                r = r.next;
            }
            node.next = r.next;
            r.next = node;
        }
        return root.next;
    }
}
