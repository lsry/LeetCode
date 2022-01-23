package L2000;

import java.util.HashMap;
import java.util.TreeMap;

public class LeetCode2034 {}

class StockPrice {

    private HashMap<Integer, Integer> map;
    private TreeMap<Integer, Integer> cnt;
    private int curTime;

    public StockPrice() {
        map = new HashMap<>();
        cnt = new TreeMap<>();
    }
    
    public void update(int timestamp, int price) {
        if (map.containsKey(timestamp)) {
            Integer p = map.get(timestamp);
            if (cnt.get(p) == 1) {
                cnt.remove(p);
            } else {
                cnt.put(p, cnt.get(p) - 1);
            }
        }
        cnt.put(price, cnt.getOrDefault(price, 0) + 1);
        if (timestamp >= curTime) {
            curTime = timestamp;
        }
        map.put(timestamp, price);
    }
    
    public int current() {
        return map.get(curTime);
    }
    
    public int maximum() {
        return cnt.lastKey();
    }
    
    public int minimum() {
        return cnt.firstKey();
    }
}