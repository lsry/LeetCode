package L1700;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class LeetCode1711 {
    class Node implements Comparable<Node> {
        public int delicious;
        public long num;

        public Node(int d, long n) {
            this.delicious = d;
            this.num = n;
        }

        @Override
        public int compareTo(Node o) {
            return this.delicious - o.delicious;
        }
        
    }
    private static final int MOD = 1_000_000_007;
    public int countPairs(int[] deliciousness) {
        int[] min2 = new int[23];
        min2[0] = 1;
        for (int i = 1;i < 23;++i) {
            min2[i] = min2[i - 1] * 2;
        }
        HashMap<Integer,Long> map = new HashMap<>();
        for (int delicious : deliciousness) {
            map.put(delicious, map.getOrDefault(delicious, 0L) + 1L);
        }
        long ans = 0;
        Node[] nodes = new Node[map.size()];
        int index = 0;
        for (Map.Entry<Integer,Long> entry : map.entrySet()) {
            nodes[index] = new Node(entry.getKey(), entry.getValue());
            ++index;
        }
        Arrays.sort(nodes);
        for (Node node : nodes) {
            for (int m2 : min2) {
                if (m2 - node.delicious >= node.delicious) {
                    if (m2 - node.delicious == node.delicious) {
                        ans = (ans + (node.num * (node.num - 1L) / 2L)) % MOD;
                    } else if (map.containsKey(m2 - node.delicious)) {
                        ans = (ans + (node.num * map.get(m2 - node.delicious))) % MOD;
                    }
                }
            }
        }
        return (int) (ans % MOD);
    }

    public static void main(String[] args) {
        LeetCode1711 code = new LeetCode1711();
        code.countPairs(new int[]{2160,1936,3,29,27,5,2503,1593,2,0,16,0,3860,28908,6,2,15,49,6246,1946,23,
            105,7996,196,0,2,55,457,5,3,924,7268,16,48,4,0,12,116,2628,1468});
    }
}