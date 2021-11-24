package L600;

public class LeetCode0677 {}

class MapSum {

    private class TireNode {
        public TireNode[] children;

        public int val;

        public TireNode() {
            children = new TireNode[26];
            val = 0;
        }
    }

    private TireNode root;

    public MapSum() {
        root = new TireNode();
    }
    
    public void insert(String key, int val) {
        TireNode cur = root;
        for (char c : key.toCharArray()) {
            if (cur.children[c - 'a'] == null) {
                cur.children[c - 'a'] = new TireNode();
            }
            cur = cur.children[c - 'a'];
        }
        cur.val = val;
    }
    
    public int sum(String prefix) {
        TireNode cur = root;
        for (char c : prefix.toCharArray()) {
            if (cur.children[c - 'a'] == null) {
                return 0;
            }
            cur = cur.children[c - 'a'];
        }
        return sum(cur);
    }

    private int sum(TireNode cur) {
        int res = cur.val;
        for (TireNode node : cur.children) {
            if (node != null) {
                res += sum(node);
            }
        }
        return res;
    }
}
