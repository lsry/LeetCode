package L700;

import java.util.Arrays;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

public class LeetCode0726 {
    class Node implements Comparable<Node> {
        public String atom;
        public int count;

        public Node(String atom, int count) {
            this.atom = atom;
            this.count = count;
        }

        @Override
        public int compareTo(Node o) {
            return atom.compareTo(o.atom);
        }
        
    }
    public String countOfAtoms(String formula) {
        if (formula == null || formula.length() == 0) {
            return "";
        }
        HashMap<String, Integer> map = new HashMap<>();
        HashMap<String, Integer> curMap = map;
        Deque<HashMap<String, Integer>> mapStack = new LinkedList<>();
        final int N = formula.length();
        for (int i = 0;i < N;) {
            char c = formula.charAt(i);
            if (c == '(') {
                mapStack.addFirst(curMap);
                curMap = new HashMap<>();
                ++i;
            } else if (c == ')') {
                ++i;
                int factor = 1;
                if (i < N && Character.isDigit(formula.charAt(i))) {
                    factor = 0;
                    while (i < N && Character.isDigit(formula.charAt(i))) {
                        factor = factor * 10 + (formula.charAt(i) - '0');
                        ++i;
                    } 
                }
                HashMap<String,Integer> anotherMap = mapStack.removeFirst();
                for (Map.Entry<String, Integer> entry : curMap.entrySet()) {
                    anotherMap.put(entry.getKey(), anotherMap.getOrDefault(entry.getKey(), 0) + entry.getValue() * factor);
                }
                curMap = anotherMap;
            } else {
                StringBuilder sb = new StringBuilder();
                sb.append(formula.charAt(i));
                ++i;
                while (i < N && formula.charAt(i) >= 'a' && formula.charAt(i) <= 'z') {
                    sb.append(formula.charAt(i));
                    ++i;
                }
                String atom = sb.toString();
                int factor = 1;
                if (i < N && Character.isDigit(formula.charAt(i))) {
                    factor = 0;
                    while (i < N && Character.isDigit(formula.charAt(i))) {
                        factor = factor * 10 + (formula.charAt(i) - '0');
                        ++i;
                    } 
                }
                curMap.put(atom, curMap.getOrDefault(atom, 0) + factor);
            }
        }
        Node[] nodes = new Node[map.size()];
        int i = 0;
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            nodes[i] = new Node(entry.getKey(), entry.getValue());
            ++i;
        }
        Arrays.sort(nodes);
        StringBuilder res = new StringBuilder();
        for (Node node : nodes) {
            res.append(node.atom);
            if (node.count > 1) {
                res.append(node.count);
            }
        }
        return res.toString();
    }
}