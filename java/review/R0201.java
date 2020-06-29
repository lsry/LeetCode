package review;

import java.util.HashSet;

import util.ListNode;

public class R0201 {
    public ListNode removeDuplicateNodesWithSpace(ListNode head) {
        ListNode h = new ListNode(0), t = h;
        HashSet<Integer> hi = new HashSet<>();
        while (head != null) {
            if (!hi.contains(head.val)) {
                t.next = head;
                hi.add(head.val);
                t = t.next;
                head = head.next;
                t.next = null;
            } else {
                head = head.next;
            }    
        }
        return h.next;
    }
}