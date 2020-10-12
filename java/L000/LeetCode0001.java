package L000;

import java.util.Arrays;
import java.util.HashMap;

/**
 * LeetCode 0001
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */

public class LeetCode0001{
    /**
     * 以哈希表做基础，将第一个元素存入哈希表，
     * 从数组第二个开始遍历，查找需要的差值是否在表中，在，则返回对应索引，否则将当前数字存入表中。
     */
    public int[] twoSumHash(int[] nums, int target) {
        HashMap<Integer,Integer> ins = new HashMap<>();
        ins.put(nums[0], 0);
        for (int i = 1;i < nums.length;i++){
            int other = target - nums[i];
            if (ins.containsKey(other)){
                return new int[]{ins.get(other),i};
            } else {
                ins.put(nums[i], i);
            }
        } 
        return new int[]{};
    }

    class Node implements Comparable<Node>{
        public int val;
        public int index;

        public Node(int val, int index) {
            this.val = val;
            this.index = index;
        }

        @Override
        public int compareTo(Node o) {
            return this.val - o.val;
        }
    }
    /**
     * 本身双重循环时，内层循环遍历数组一次
     * 在数组有序时，可以利用二叉查找将内层循环降到 log(n)
     * 因此需要先排序，但同时要记住每一个元素的索引位置
     */
    public int[] twoSum(int[] nums, int target) {
        Node[] nodes = new Node[nums.length];
        for (int i = 0;i < nums.length;++i) {
            nodes[i] = new Node(nums[i], i);
        }
        Arrays.sort(nodes);
        for (int i = 0;i < nodes.length - 1;++i) {
            int le = i + 1, ri = nodes.length - 1;
            while (le <= ri) {
                int mid = le + (ri - le) / 2;
                if (nodes[i].val + nodes[mid].val == target) {
                    return new int[]{nodes[i].index, nodes[mid].index};
                } else if (nodes[i].val + nodes[mid].val < target) {
                    le = mid + 1;
                } else {
                    ri = mid - 1;
                }
            }
        }
        return new int[]{};
    }
}