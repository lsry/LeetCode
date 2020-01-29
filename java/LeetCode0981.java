import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LeetCode0981 {
}

class TimeMapTLE {
    class Node{
        public String value;
        public int timestamp;
        public Node next;

        public Node (String v,int t) {
            value = v;
            timestamp = t;
            next = null;
        }
    }

    public Map<String,Node> data;

    /** Initialize your data structure here. */
    public TimeMapTLE() {
        data = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        Node cur = data.getOrDefault(key, null);
        if (cur == null) {
            data.put(key, new Node(value,timestamp));
        } else if (cur.timestamp > timestamp) {
            Node other = new Node(value, timestamp);
            other.next = cur;
            data.put(key, other);
        } else {
            Node temp = cur;
            while (temp.next != null && temp.next.timestamp <= timestamp) {
                temp = temp.next;
            }
            Node other = new Node(value, timestamp);
            other.next = temp.next;
            temp.next = other;
            data.put(key, cur);
        }
    }
    
    public String get(String key, int timestamp) {
        Node cur = data.getOrDefault(key, null);
        if (cur == null || cur.timestamp > timestamp) {
            return "";
        } 
        while (cur.next != null && cur.next.timestamp <= timestamp) {
            cur = cur.next;
        }
        return cur.value;
    }
}

class TimeMap {
    class Node{
        public String value;
        public int timestamp;

        public Node (String v,int t) {
            value = v;
            timestamp = t;
        }
    }

    public Map<String,List<Node>> data;

    /** Initialize your data structure here. */
    public TimeMap() {
        data = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        Node cur = new Node(value,timestamp);
        List<Node> curList = data.getOrDefault(key, new ArrayList<>(8));
        curList.add(cur);
        data.put(key, curList);
    }
    
    public String get(String key, int timestamp) {
        List<Node> curList = data.getOrDefault(key, null);
        if (curList == null || curList.size() == 0 || timestamp < curList.get(0).timestamp) {
            return "";
        }
        int left = 0, right = curList.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int curstamp = curList.get(mid).timestamp;
            if (curstamp == timestamp) {
                return curList.get(mid).value;
            } else if (curstamp < timestamp) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (left > 0) --left;
        return curList.get(left).value;
    }
}