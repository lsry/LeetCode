package L100;

import java.util.LinkedList;
import java.util.Queue;

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
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

public class LeetCode0117 {
    /**
     * BFS
     * 用队列获得每一层，然后挨个连接
     */
    public Node connectBFS_QUEUE(Node root) {
        if (root == null) {
            return root;
        }
        Queue<Node> qu = new LinkedList<>();
        qu.offer(root);
        while (!qu.isEmpty()) {
            int sz = qu.size();
            Node cur = qu.poll();
            if (cur.left != null) {
                qu.offer(cur.left);
            }
            if (cur.right != null) {
                qu.offer(cur.right);
            }
            for (int i = 1;i < sz;++i) {
                Node next = qu.poll();
                if (next.left != null) {
                    qu.offer(next.left);
                }
                if (next.right != null) {
                    qu.offer(next.right);
                }
                cur.next = next;
                cur = next;
            }
        }
        return root;
    }
}
