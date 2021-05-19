package L400;

public class LeetCode0421 {
    private class Node {
        public Node left;
        public Node right;
        public Node() {
            left = null;
            right = null;
        }
    }

    private Node root = new Node();
    private static final int BITS = 30;

    private void add(int val) {
        Node cur = root;
        for (int i = BITS;i >= 0;--i) {
            if (((val >> i) & 1) == 1) {
                if (cur.right == null) {
                    cur.right = new Node();
                }
                cur = cur.right;
            } else {
                if (cur.left == null) {
                    cur.left = new Node();
                }
                 cur = cur.left;
            }
        }
    }

    private int maxXOR(int val) {
        int res = 0;
        Node cur = root;
        for (int i = BITS;i >= 0;--i) {
            if (((val >> i) & 1) == 1) {
                if (cur.left != null) {
                    res = res * 2 + 1;
                    cur = cur.left;
                } else {
                    res = res * 2;
                    cur = cur.right;
                }
            } else {
                if (cur.right != null) {
                    res = res * 2 + 1;
                    cur = cur.right;
                } else {
                    res = res * 2;
                    cur = cur.left;
                }
            }
        }
        return res;
    }
    public int findMaximumXOR(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return 0;
        }
        int x = 0;
        for (int i = 1;i < nums.length;++i) {
            add(nums[i - 1]);
            x = Math.max(x, maxXOR(nums[i]));
        }
        return x;
    }
}
