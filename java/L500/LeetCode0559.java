package L500;

import java.util.List;

public class LeetCode0559 {
    private static class Node {
        public List<Node> children;
    }

    public int maxDepth(Node root) {
        if (root == null) {
            return 0;
        }
        int max = 0;
        for (Node child : root.children) {
            max = Math.max(max, maxDepth(child));
        }
        return max + 1;
    }
}
