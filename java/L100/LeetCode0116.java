package L100;

public class LeetCode0116 {
    private class Node {
        public int val;
        public Node left;
        public Node right;
        public Node next;
        
        public Node(int _val) {
            val = _val;
        }
    
        public Node(int _val, Node _left, Node _right, Node _next) {
            val = _val;
            left = _left;
            right = _right;
            next = _next;
        }
    }

    public Node connect(Node root) {
        Node first = root;
        while (first != null) {
            Node node = first;
            Node head = new Node(0);
            Node tail = head;
            while (node != null) {
                if (node.left != null) {
                    tail.next = node.left;
                    tail = tail.next;
                }
                if (node.right != null) {
                    tail.next = node.right;
                    tail = tail.next;
                }
                node = node.next;
            }
            first = head.next;
        }
        return root;
    }
}
