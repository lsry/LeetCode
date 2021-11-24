package L300;

import java.util.Arrays;
import java.util.LinkedList;

public class LeetCode0384 {}

class Solution {

    private int[] nums, lastShuffled;

    public Solution(int[] nums) {
        this.nums = nums;
        this.lastShuffled = Arrays.copyOf(nums, nums.length);
    }
    
    public int[] reset() {
        lastShuffled = Arrays.copyOf(nums, nums.length);
        return lastShuffled;
    }
    
    public int[] shuffle() {
        int[] shuffled = new int[nums.length];
        LinkedList<Integer> list = new LinkedList<>();
        for (int i = 0;i < nums.length;i++) {
            list.add(lastShuffled[i]);
        }
        for (int i = 0;i < nums.length;i++) {
            int index = (int)(Math.random() * list.size());
            shuffled[i] = list.get(index);
            list.remove(index);
        }
        lastShuffled = shuffled;
        return shuffled;
    }
}