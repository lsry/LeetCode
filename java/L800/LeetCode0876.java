package L800;

import java.util.ArrayList;
import java.util.List;

import util.ListNode;

public class LeetCode0876{
    public ListNode middleNodeSpace(ListNode head) {
        if (head == null){
            return null;
        }
        List<ListNode> li = new ArrayList<>();
        ListNode h0 = head;
        while(h0 != null){
            li.add(h0);
            h0 = h0.next;
        }
        return li.get(li.size()/2);
    }

    public ListNode middleNode(ListNode head) {
        if (head == null) {
            return null;
        }
        int length = 0;
        ListNode h0 = head;
        while (h0 != null) {
            ++length;
            h0 = h0.next;
        }
        int i = 0;
        for (h0 = head;i < length / 2;++i) {
            h0 = h0.next;
        }
        return h0;
    }
}