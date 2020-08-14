package L000;

import util.ListNode;

public class LeetCode0025 {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode res = new ListNode(0), tail = res;
        while (head != null) {
            ListNode kgroup = new ListNode(0),ktail = kgroup;
            int i = 0;
            for (;i < k && head != null;++i) {
                ListNode cur = head;
                head = head.next;
                if (i == 0) {
                    ktail = cur;
                }
                cur.next = kgroup.next;
                kgroup.next = cur;
            }
            if (i == k) {
                tail.next = kgroup.next;
                tail = ktail;
            } else {
                kgroup = kgroup.next;
                while (kgroup != null) {
                    ListNode cur = kgroup;
                    kgroup = kgroup.next;
                    cur.next = tail.next;
                    tail.next = cur;
                }
                break;
            }
        }
        return res.next;
    }
}