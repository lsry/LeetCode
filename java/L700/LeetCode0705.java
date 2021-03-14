package L700;

public class LeetCode0705 {}

class MyHashSet {
    class Entry {
        int key;
        Entry next;

        public Entry(int key) {
            this.key = key;
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
    public MyHashSet() {
        values = new Entry[cap];
        size = 0;
    }

    private void ensure() {
        if ((size + 1) * 1.0 / cap > facor) {
            cap = cap * 2;
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
    
    public void add(int key) {
        ensure();
        int hash = key % cap;
        if (values[hash] == null) {
            values[hash] = new Entry();
        }
        Entry cur = values[hash];
        while (cur.next != null) {
            if (cur.next.key == key) {
                return;
            }
            cur = cur.next;
        }
        cur.next = new Entry(key);
        size += 1;
    }

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
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        int hash = key % cap;
        Entry cur = values[hash];
        while (cur != null && cur.next != null) {
            if (cur.next.key == key) {
                return true;
            }
            cur = cur.next;
        }
        return false;
    }
}
