package L400;

import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;

public class LeetCode0496 {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Deque<Integer> stack = new LinkedList<>();
        HashMap<Integer,Integer> map = new HashMap<>();
        for (int i = 0;i < nums2.length;++i) {
            while (!stack.isEmpty() && stack.getFirst() < nums2[i]) {
                map.put(stack.removeFirst(), nums2[i]);
            }
            stack.addFirst(nums2[i]);
        }
        int[] res = new int[nums1.length];
        for (int i = 0;i < nums1.length;++i) {
            res[i] = map.getOrDefault(nums1[i], -1);
        }
        return res;
    }
}
