package L700;

public class LeetCode0706 {}

class MyHashMap {

    class Entry {
        int key, value;
        Entry next;

        public Entry(int key, int value) {
            this.key = key;
            this.value = value;
            next = null;
        }

        public Entry() {
            next = null;
        }
    }

    private Entry[] values;
    private int size;
    private int cap = 8;
    private static final double facor = 0.75;

    /** Initialize your data structure here. */
    public MyHashMap() {
        values = new Entry[cap];
        size = 0;
    }

    private void ensure() {
        if (cap == Integer.MAX_VALUE) {
            return;
        }
        if ((size + 1) * 1.0 / cap > facor) {
            cap = cap < Integer.MAX_VALUE / 2 ? cap * 2 : Integer.MAX_VALUE;
            Entry[] tmp = new Entry[cap];
            for (Entry entry : values) {
                while (entry != null && entry.next != null) {
                    Entry cur = entry.next;
                    entry.next = cur.next;
                    cur.next = null;
                    int hash = cur.key % cap;
                    if (tmp[hash] == null) {
                        tmp[hash] = new Entry();
                    }
                    cur.next = tmp[hash].next;
                    tmp[hash].next = cur;
                }
            }
            values = tmp;
        }
    }
    
    /** value will always be non-negative. */
    public void put(int key, int value) {
        ensure();
        int hash = key % cap;
        if (values[hash] == null) {
            values[hash] = new Entry();
        }
        Entry cur = values[hash];
        while (cur.next != null) {
            if (cur.next.key == key) {
                cur.next.value = value;
                return;
            }
            cur = cur.next;
        }
        cur.next = new Entry(key, value);
        size += 1;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        int hash = key % cap;
        Entry cur = values[hash];
        while (cur != null && cur.next != null) {
            if (cur.next.key == key) {
                return cur.next.value;
            }
            cur = cur.next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        int hash = key % cap;
        Entry cur = values[hash];
        while (cur != null && cur.next != null) {
            if (cur.next.key == key) {
                cur.next = cur.next.next;
                size -= 1;
                break;
            }
            cur = cur.next;
        }
    }
}
