package L700;

import java.util.PriorityQueue;

public class LeetCode0767 {
    private class Node {
        public char letter;
        public int count;

        public Node(char letter) {
            this.letter = letter;
            this.count = 0;
        }
    }
    public String reorganizeString(String S) {
        if (S == null || S.length() <= 1) {
            return S;
        }
        Node[] nodes = new Node[26];
        for (int i = 0;i < 26;++i) {
            nodes[i] = new Node((char)('a' + i));
        }
        for (char c : S.toCharArray()) {
            nodes[c - 'a'].count += 1;
        }
        PriorityQueue<Node> pq = new PriorityQueue<>(26, (n1, n2) -> {
            return n2.count - n1.count;
        });
        for (int i = 0;i < 26;++i) {
            if (nodes[i].count != 0) {
                pq.offer(nodes[i]);
            }
        }
        StringBuilder res = new StringBuilder();
        while (pq.size() >= 2) {
            Node n1 = pq.poll();
            Node n2 = pq.poll();
            for (int i = 0;i < n2.count;++i) {
                res.append(n1.letter);
                res.append(n2.letter);
            }
            n1.count -= n2.count;
            if (pq.isEmpty() && n1.count > 0) {
                res.append(n1.letter);
                break;
            }
            pq.offer(n1);
        }
        return res.length() == S.length() ? res.toString() : "";
    }
}
