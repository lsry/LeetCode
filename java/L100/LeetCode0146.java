package L100;

import java.util.HashMap;
import java.util.Map;

public class LeetCode0146 {}

class LRUCache {
    class DNode {
        int key;
        int value;
        DNode prev, next;
        public DNode(int k, int v) {
            key = k;
            value = v;
        }
    }
    private int cap;
    private DNode head;
    private Map<Integer,DNode> cache;

    public LRUCache(int capacity) {
        cache = new HashMap<>();
        head = new DNode(0, 0);
        head.next = head;
        head.prev = head;
        cap = capacity;
    }

    public void addToHead(DNode cur) {
        cur.next = head.next;
        head.next.prev = cur;
        head.next = cur;
        cur.prev = head;
    }

    public void removeNode(DNode cur) {
        cur.next.prev = cur.prev;
        cur.prev.next = cur.next;
    }
    
    public int get(int key) {
        if (!cache.containsKey(key)) {
            return -1;
        }
        DNode cur = cache.get(key);
        removeNode(cur);
        addToHead(cur);
        return cur.value;
    }
    
    public void put(int key, int value) {
        if (cache.containsKey(key)) {
            DNode cur = cache.get(key);
            cur.value = value;
            removeNode(cur);
            addToHead(cur);
        } else if (cache.size() < cap) {
            DNode cur = new DNode(key,value);
            cache.put(key, cur);
            addToHead(cur);
        } else {
            DNode cur = head.prev;
            cache.remove(cur.key);
            head.prev = cur.prev;
            cur.prev.next = head;
            cur.key = key;
            cur.value = value;
            addToHead(cur);
            cache.put(key, cur);
        }
    }
}