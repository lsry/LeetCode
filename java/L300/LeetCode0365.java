package L300;

import java.util.Deque;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Set;

public class LeetCode0365 {
    class Node {
        public int x,y;

        public Node(int x,int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (o == this) return true;
            if (o == null || !(o instanceof Node)) {
                return false;
            }
            Node n = (Node) o;
            return x == n.x && y == n.y;
        }

        @Override
        public int hashCode() {
            return x * 31 + y;
        }
        
    }
    public boolean canMeasureWater(int x, int y, int z) {
        Deque<Node> stack = new LinkedList<>();
        Set<Node> set = new HashSet<>();
        Node n0 = new Node(0,0);
        stack.addFirst(n0);
        while (!stack.isEmpty()) {
            Node n = stack.removeFirst();
            if (n.x == z || n.y == z || n.x + n.y == z) {
                return true;
            }
            if (set.contains(n)) {
                continue;
            }
            set.add(n);
            stack.addFirst(new Node(n.x,0));
            stack.addFirst(new Node(0,n.y));
            stack.addFirst(new Node(x,n.y));
            stack.addFirst(new Node(n.x,y));
            if (n.x < y - n.y) {
                stack.addFirst(new Node(0,n.x + n.y));
            } else {
                stack.addFirst(new Node(n.x - y + n.y,y));
            }
            if (n.y < x - n.x) {
                stack.addFirst(new Node(n.x + n.y,0));
            } else {
                stack.addFirst(new Node(x,n.y + n.x -x));
            }
        }
        return false;
    }
}