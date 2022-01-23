package L300;

import util.ListNode;

public class LeetCode0382 {}

class Solution {

    private ListNode head;

    public Solution(ListNode head) {
        if (head == null) {
            throw new NullPointerException();
        }
        this.head = head;
    }
    
    public int getRandom() {
        ListNode cur = head;
        int val = cur.val;
        for (int i = 1;cur != null;++i) {
            if (Math.random() <= 1.0 / i) {
                val = cur.val;
            }
            cur = cur.next;
        }
        return val;
    }
}
