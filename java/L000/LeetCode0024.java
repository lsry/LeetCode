package L000;

import util.ListNode;

public class LeetCode0024 {

    /**
     * 考虑逆序K个元素，首先先判断是否有 K 个，
     * 无，则直接接到新链表尾部
     * 有，用头插法插入链表
     */
    public ListNode exchangeK(ListNode head,int k){
        ListNode h0 = new ListNode(0);
        h0.next = head;
        ListNode before_cur = h0;
        ListNode last = h0;
        ListNode cur = head;
        ListNode cur_head = cur;
        while (cur != null){
            cur_head = cur;
            int i = 0;
            for (;i < k && cur != null;i++){
                before_cur = cur;
                cur = cur.next;
            }
            if (i == k){
                before_cur.next = null;
                ListNode temp = cur_head;
                while (cur_head != null){
                    ListNode t = cur_head;
                    cur_head = cur_head.next;
                    t.next = last.next;
                    last.next = t;      
                }
                last = temp;
            } else {
                break;
            }
        }
        last.next = cur_head;
        return h0.next;
    }

    public ListNode swapPairsGenerK(ListNode head) {
        return exchangeK(head, 2);
    }

    /**
     * 判断是否有两个结点，有则更改链表指针
     */
    public ListNode swapPairs(ListNode head) {
        ListNode h0 = new ListNode(0);
        ListNode tail = h0;
        ListNode cur = head;
        while (cur != null && cur.next != null) {
            ListNode temp = cur.next.next;
            tail.next = cur.next;
            cur.next.next = cur;
            cur.next = null;
            tail = cur;
            cur = temp;
        }
        if (cur != null) {
            tail.next = cur;
        }
        return h0.next;
    }

    public static void main(String[] args) {
        
    }
}