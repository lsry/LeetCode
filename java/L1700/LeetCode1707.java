package L1700;

import java.util.Arrays;

public class LeetCode1707 {
    private class Node {
        public Node[] next;

        public Node() {
            next = new Node[2];
        }
    }

    private Node root = new Node();
    private static final int BITS = 31;

    private void addNode(int num) {
        Node cur = root;
        for (int i = BITS;i >= 0;--i) {
            if (((num >>> i) & 1) == 1) {
                if (cur.next[1] == null) {
                    cur.next[1] = new Node();
                }
                cur = cur.next[1];
            } else {
                if (cur.next[0] == null) {
                    cur.next[0] = new Node();
                }
                cur = cur.next[0];
            }
        }
    }

    private int getMaxXOR(int num) {
        if (root.next[0] == null && root.next[1] == null) {
            return -1;
        }
        Node cur = root;
        int res = 0;
        for (int i = BITS;i >= 0;--i) {
            if (((num >>> i) & 1) == 1) {
                if (cur.next[0] != null) {
                    res = res * 2 + 1;
                    cur = cur.next[0];
                } else {
                    res = res * 2;
                    cur = cur.next[1];
                }
            } else {
                if (cur.next[1] != null) {
                    res = res * 2 + 1;
                    cur = cur.next[1];
                } else {
                    res = res * 2;
                    cur = cur.next[0];
                }
            }
        }
        return res;
    }

    public int[] maximizeXor(int[] nums, int[][] queries) {
        Arrays.sort(nums);
        int[][] tmp = new int[queries.length][3];
        for (int i = 0;i < queries.length;++i) {
            tmp[i][0] = queries[i][0];
            tmp[i][1] = queries[i][1];
            tmp[i][2] = i;
        }
        Arrays.sort(tmp, (a, b) -> {
            return a[1] - b[1];
        });
        int index = 0;
        int[] res = new int[queries.length];
        for (int i = 0;i < queries.length;++i) {
            while (index < nums.length && nums[index] <= tmp[i][1]) {
                addNode(nums[index]);
                ++index;
            }
            res[tmp[i][2]] = getMaxXOR(tmp[i][0]);
        }
        return res;
    }
}
