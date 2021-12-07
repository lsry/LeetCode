package L500;

import java.util.HashMap;
import java.util.Random;

public class LeetCode0519 {}

class Solution {
    private HashMap<Integer, Integer> map;
    private int m, n;
    private int total;
    private Random random;

    public Solution(int m, int n) {
        map = new HashMap<>();
        this.m = m;
        this.n = n;
        total = m * n;
        random = new Random();
    }
    
    public int[] flip() {
        int idx = random.nextInt(total);
        int mapIdx = map.getOrDefault(idx, idx);
        --total;
        map.put(idx, map.getOrDefault(total, total));
        return new int[]{mapIdx / n, mapIdx % n};
    }
    
    public void reset() {
        map.clear();
        total = m * n;
    }
}