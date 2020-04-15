import java.util.ArrayDeque;
import java.util.Deque;

public class LeetCode0445 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Deque<ListNode> n1 = new ArrayDeque<>();
        Deque<ListNode> n2 = new ArrayDeque<>();
        ListNode head = l1;
        while (head != null) {
            n1.addFirst(head);
            head = head.next;
        }
        head = l2;
        while (head != null) {
            n2.addFirst(head);
            head = head.next;
        }
        ListNode res = new ListNode(0);
        int C = 0;
        while (!n1.isEmpty() && !n2.isEmpty()) {
            ListNode node1 = n1.removeFirst();
            ListNode node2 = n2.removeFirst();
            int sum = node1.val + node2.val + C;
            ListNode n = new ListNode(sum % 10);
            C = sum / 10;
            n.next = res.next;
            res.next = n;
        }
        if (!n1.isEmpty()) {
            while (!n1.isEmpty()) {
                int val = n1.removeFirst().val;
                ListNode n = new ListNode((val + C) % 10);
                C = (val + C) / 10;
                n.next = res.next;
                res.next = n;
            }
        }
        if (!n2.isEmpty()) {
            while (!n2.isEmpty()) {
                int val = n2.removeFirst().val;
                ListNode n = new ListNode((val + C) % 10);
                C = (val + C) / 10;
                n.next = res.next;
                res.next = n;
            }
        }
        if (C != 0) {
            ListNode n = new ListNode(C);
            n.next = res.next;
            res.next = n;
        }
        return res.next;
    }
}