package L100;

import util.ListNode;

public class LeetCode0160 {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode ha = headA, hb = headB;
        int la = 0, lb = 0;
        while (ha != null) {
            ++la;
            ha = ha.next;
        }
        while (hb != null) {
            ++lb;
            hb = hb.next;
        }
        ha = headA;
        hb = headB;
        if (la > lb) {
            while (la != lb) {
                --la;
                ha = ha.next;
            }
        } else {
            while (lb != la) {
                --lb;
                hb = hb.next;
            }
        }
        while (ha != null && hb != null) {
            if (ha == hb) {
                return ha;
            }
            ha = ha.next;
            hb = hb.next;
        }
        return null;
    }
}
