package L000;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LeetCode0049 {
    private class Node {
        int[] alphs;

        public Node(String str) {
            alphs = new int[26];
            for (char c : str.toCharArray()) {
                alphs[c - 'a'] += 1;
            }
        }

        @Override
        public int hashCode() {
            int res = 0;
            for (int alph : alphs) {
                res += res * 31 + alph;
            }
            return res;
        }

        @Override 
        public boolean equals(Object obj) {
            if (obj == this) {
                return true;
            }
            if (obj == null || !(obj instanceof Node)) {
                return false;
            }
            Node node = (Node) obj;
            for (int i = 0;i < alphs.length;++i) {
                if (node.alphs[i] != this.alphs[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<>();
        if (strs.length == 0) {
            return res;
        }
        HashMap<Node, List<String>> map = new HashMap<>();
        for (String str : strs) {
            Node node = new Node(str);
            if (map.containsKey(node)) {
                map.get(node).add(str);
            } else {
                List<String> cList = new ArrayList<>();
                cList.add(str);
                map.put(node, cList);
            }
        }
        for (Map.Entry<Node, List<String>> entry : map.entrySet()) {
            res.add(entry.getValue());
        }
        return res;
    }

    
}
