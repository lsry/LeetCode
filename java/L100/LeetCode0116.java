package L100;

public class LeetCode0116 {
    private class Node {
        public Node left;
        public Node right;
        public Node next;
        
        public Node() {}
    }

    public Node connect(Node root) {
        Node first = root;
        while (first != null) {
            Node node = first;
            Node head = new Node();
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
