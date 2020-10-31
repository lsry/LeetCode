package L300;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

public class LeetCode0381 {
}

class RandomizedCollection {
    private HashMap<Integer,List<Integer>> vMap;
    private List<Integer> nums;
    private Random random;

    /** Initialize your data structure here. */
    public RandomizedCollection() {
        this.vMap = new HashMap<>();
        this.nums = new ArrayList<>();
        this.random = new Random();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public boolean insert(int val) {
        nums.add(val);
        boolean res = false;
        if (!vMap.containsKey(val)) {
            vMap.put(val, new LinkedList<>());
        }
        List<Integer> indics = vMap.get(val);
        if (indics.isEmpty()) {
            res = true;
        }
        indics.add(nums.size() - 1);
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    public boolean remove(int val) {
        if (!vMap.containsKey(val)) {
            return false;
        }
        List<Integer> indics = vMap.get(val);
        if (indics.isEmpty()) {
            return false;
        }
        int index = indics.remove(indics.size() - 1);
        if (nums.size() - 1 != index) {
            int ankey = nums.get(nums.size() - 1);
            nums.set(index, ankey);
            List<Integer> li = vMap.get(ankey);
            li.remove(Integer.valueOf(nums.size() - 1));
            li.add(index);
        }
        nums.remove(nums.size() - 1);
        return true;
    }
    
    /** Get a random element from the collection. */
    public int getRandom() {
        return nums.get(random.nextInt(nums.size()));
    }
}
