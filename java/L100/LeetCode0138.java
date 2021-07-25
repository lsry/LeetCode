package L100;

import java.util.HashMap;

public class LeetCode0138 {
    class Node {
        int val;
        Node next;
        Node random;
    
        public Node(int val) {
            this.val = val;
            this.next = null;
            this.random = null;
        }
    }
    public Node copyRandomList(Node head) {
        Node dummy = new Node(0);
        Node tail = dummy;
        HashMap<Node, Node> map = new HashMap<>();
        Node h = head;
        while (h != null) {
            map.put(h, new Node(h.val));
            h = h.next;
        }
        h = head;
        while (h != null) {
            Node cur = map.get(h);
            if (h.random != null) {
                cur.random = map.get(h.random);
            }
            h = h.next;
            tail = cur;
            tail = tail.next;
        }
        return dummy.next;
    }
}