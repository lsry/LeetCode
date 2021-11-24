package L300;

import java.util.HashMap;
import java.util.Map;

public class LeetCode0391 {
    private class Node {
        public int x;
        public int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public boolean equals(Object o) {
            if (o == this) {
                return true;
            }
            if (!(o instanceof Node)) {
                return false;
            }
            Node n = (Node) o;
            return n.x == x && n.y == y;
        }

        public int hashCode() {
            return x * 31 + y;
        }
    }

    public boolean isRectangleCover(int[][] rectangles) {
        int x1 = Integer.MAX_VALUE, x2 = Integer.MIN_VALUE, y1 = Integer.MAX_VALUE, y2 = Integer.MIN_VALUE;
        long area = 0;
        HashMap<Node, Integer> map = new HashMap<>();
        for (int[] rectangle : rectangles) {
            x1 = Math.min(x1, rectangle[0]);
            x2 = Math.max(x2, rectangle[2]);
            y1 = Math.min(y1, rectangle[1]);
            y2 = Math.max(y2, rectangle[3]);
            area += (long) (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
            Node n1 = new Node(rectangle[0], rectangle[1]);
            Node n2 = new Node(rectangle[2], rectangle[3]);
            Node n3 = new Node(rectangle[0], rectangle[3]);
            Node n4 = new Node(rectangle[2], rectangle[1]);
            map.put(n1, map.getOrDefault(n1, 0) + 1);
            map.put(n2, map.getOrDefault(n2, 0) + 1);
            map.put(n3, map.getOrDefault(n3, 0) + 1);
            map.put(n4, map.getOrDefault(n4, 0) + 1);
        }
        Node n1 = new Node(x1, y1);
        Node n2 = new Node(x2, y1);
        Node n3 = new Node(x1, y2);
        Node n4 = new Node(x2, y2);
        if (area != (long)(x2 - x1) * (y2 - y1) || map.getOrDefault(n1, 0) != 1 || map.getOrDefault(n2, 0) != 1
                || map.getOrDefault(n3, 0) != 1 || map.getOrDefault(n4, 0) != 1) {
            return false;
        }
        map.remove(n1);
        map.remove(n2);
        map.remove(n3);
        map.remove(n4);
        for (Map.Entry<Node, Integer> entry : map.entrySet()) {
            if (!(entry.getValue() == 2 || entry.getValue() == 4)) {
                return false;
            }
        }
        return true;
    }
}
