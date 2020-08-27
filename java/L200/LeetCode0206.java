package L200;

import util.ListNode;

public class LeetCode0206 {
    /**
     * 循环解法，运用头插法
     */
    public ListNode reverseListIter(ListNode head) {
        ListNode ch = new ListNode(0);
        ListNode temp;
        while (head != null) {
            temp = head.next;
            head.next = ch.next;
            ch.next = head;
            head = temp;
        }
        return ch.next;
    }
    
    /**
     * 递归解法，记住链表头结点，递归中，返回每个结果的尾结点，然后将当前结点插入最后
     */
    private ListNode ch;
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode cue = helper(head);  // 要注意要将尾结点赋值为空，否则成环状
        cue.next = null;
        return ch;
    } 
    public ListNode helper(ListNode head) {
        if (head.next == null) {
            ch = head;
            return head;
        }
        ListNode cur = head;
        ListNode tail = helper(head.next);
        tail.next = cur;
        return cur;
    }
    
}