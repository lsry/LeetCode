public class LeetCode0021{
    // 类似归并排序子过程，需要建立头结点
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode h0 = head;
        ListNode h1 = l1;
        ListNode h2 = l2;
        while (h1 != null && h2 != null){
            if (h1.val < h2.val){
                h0.next = h1;
                h1 = h1.next;
            } else {
                h0.next = h2;
                h2 = h2.next;
            }
            h0 = h0.next;
        }
        h0.next = h1 == null ? h2 : h1;
        return head.next;
    }
}