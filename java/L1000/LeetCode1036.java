package L1000;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class LeetCode1036 {
    class Node {
        public int x;
        public int y;

        public Node(int x,int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || !(o instanceof Node)) {
                return false;
            }
            Node n = (Node) o;
            return n.x == this.x && n.y == this.y;
        }

        @Override
        public int hashCode() {
            return x * 31 + y;
        }
    }

    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        Set<Node> blockSet = new HashSet<>();
        for (int[] block : blocked) {
            blockSet.add(new Node(block[0],block[1]));
        }
        return !isAroundPoint(source, target, blockSet) && !isAroundPoint(target, source, blockSet);
    }

    /**
     * 判断 source 是否被完全包裹在block所形成的的区域中
     * 假设block总数为 N，最大面积为 N * (N - 1) / 2
     */
    public boolean isAroundPoint(int[] source,int[] target,Set<Node> blockSet) {
        int count = 0;
        int S = (blockSet.size()) * (blockSet.size() - 1) / 2 + 1;
        Set<Node> seen = new HashSet<>();
        seen.add(new Node(source[0],source[1]));
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(source[0],source[1]));
        int[][] indexes = new int[][]{{0,-1},{0,1},{-1,0},{1,0}};
        while (!queue.isEmpty()) {
            Node cur = queue.poll();
            if (cur.x == target[0] && cur.y == target[1]) {
                return false;
            }
            if (count >= S) {
                return false;
            }
            for (int[] index : indexes) {
                Node temp = new Node(cur.x + index[0],cur.y + index[1]);
                if (temp.x >= 0 && temp.x < 1e6 && temp.y >= 0 && temp.y < 1e6 
                    && !blockSet.contains(temp) && !seen.contains(temp)) {
                    seen.add(temp);
                    queue.offer(temp);
                    ++count;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int[][] blocks = new int[][]{{0,1},{1,0}};
        int[] sou = new int[]{0,0};
        int[] tar = new int[]{0,2};
        LeetCode1036 l36 = new LeetCode1036();
        l36.isEscapePossible(blocks, sou, tar);
    }
}