package L1300;

import java.util.Arrays;

public class LeetCode1365 {
    private class Node implements Comparable<Node>{
        public int index;
        public int value;

        public Node(int i, int v) {
            index = i;
            value = v;
        }

        @Override
        public int compareTo(Node n) {
            return this.value - n.value;
        }

    }
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] res = new int[nums.length];
        Node[] nodes = new Node[nums.length];
        for (int i = 0;i < nums.length;++i) {
            nodes[i] = new Node(i, nums[i]);
        }
        Arrays.sort(nodes);
        int front = 1;
        res[nodes[0].index] = 0;
        for (int i = 1;i < nodes.length;++i) {
            if (nodes[i].value == nodes[i - 1].value) {
                res[nodes[i].index] = res[nodes[i - 1].index];
            } else {
                res[nodes[i].index] = front;
            }
            ++front;
        }
        return res;
    }
}
