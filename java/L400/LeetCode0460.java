package L400;

import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.Map;

public class LeetCode0460 {

}

class LFUCache {
    class Node {
        public int key,value,freq;

        public Node(int k,int v) {
            key = k;
            value = v;
            freq = 1;
        }

        @Override
        public boolean equals(Object o) {
            if (o == this) return true;
            if (o == null || o.getClass() != this.getClass()) return false;
            Node n = (Node) o;
            return n.key == this.key;
        }

        @Override
        public int hashCode() {
            return key;
        }
    }

    Map<Integer,Node> cache;
    Map<Integer,LinkedHashSet<Node>> freqMap;
    int size;
    int capacity;
    int minFreq;

    public LFUCache(int capacity) {
        cache = new HashMap<>(capacity);
        freqMap = new HashMap<>();
        size = 0;
        this.capacity = capacity;
        minFreq = 0;
    }
    
    public int get(int key) {
        Node cur = cache.get(key);
        if (cur == null) {
            return -1;
        }
        freqInc(cur);
        return cur.value;
    }

    public void freqInc(Node node) {
        freqMap.get(node.freq).remove(node);
        if (minFreq == node.freq && freqMap.get(node.freq).isEmpty()) {
            minFreq++;
        }
        LinkedHashSet<Node> sets = freqMap.get(node.freq + 1);
        if (sets == null) {
            sets = new LinkedHashSet<>();
            freqMap.put(node.freq + 1, sets);
        }
        node.freq = node.freq + 1;
        sets.add(node);
    }
    
    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        Node cur = cache.get(key);
        if (cur != null) {
            cur.value = value;
            freqInc(cur);
        } else {
            if (capacity == size) {
                LinkedHashSet<Node> set = freqMap.get(minFreq);
                Node deNode = set.iterator().next();
                set.remove(deNode);
                cache.remove(deNode.key);
                --size;
            }
            Node newNode = new Node(key,value);
            cache.put(key, newNode);
            LinkedHashSet<Node> set = freqMap.get(1);
            if (set == null) {
                set = new LinkedHashSet<>();
                freqMap.put(1, set);
            }
            set.add(newNode);
            ++size;
            minFreq = 1;
        }
    }
}