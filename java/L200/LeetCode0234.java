package L200;

import util.ListNode;

public class LeetCode0234 {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        ListNode slow = head;
        ListNode fast = head.next.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode half = new ListNode(0);
        ListNode md = slow.next;
        slow.next = null;
        while (md != null) {
            ListNode t = md.next;
            md.next = half.next;
            half.next = md;
            md = t;
        }
        slow = head;
        while (slow != null && half.next != null) {
            if (slow.val != half.next.val) {
                return false;
            }
            slow = slow.next;
            half = half.next;
        }
        return true;  // 当长度为偶数，两个均遍历到末尾，若为奇数，则存在多余的一个节点不被比较
    }
}
