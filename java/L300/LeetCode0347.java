package L300;

import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Arrays;

public class LeetCode0347 {

    public class Node implements Comparable<Node>{
        public int key;
        public int count;

        public Node(int k,int c){
            this.key = k;
            this.count = c;
        }

        @Override
        public int compareTo(Node n) {
            return this.count - n.count;
        }

    }

    // 统计每个数出现频率，然后排序，找出出现频率最高K的数
    public List<Integer> topKFrequentSort(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for (int n : nums){
            map.put(n,map.getOrDefault(n, 0) + 1);
        }

        Node[] nodes = new Node[map.size()];
        int index = 0;
        for (Map.Entry<Integer,Integer> entry : map.entrySet()){
            nodes[index] = new Node(entry.getKey(),entry.getValue());
            index++;
        }

        Arrays.sort(nodes);

        List<Integer> li = new ArrayList<>(k);
        for (int i = nodes.length - 1;i >= nodes.length - k;i--){
            li.add(nodes[i].key);
        }

        return li;
    }

    // 小根堆取最高K个元素
    // 大根堆取最低K个元素
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for (int n : nums){
            map.put(n,map.getOrDefault(n, 0) + 1);
        }
        PriorityQueue<Node> pq = new PriorityQueue<>((n1,n2) -> {
            return  n1.count - n2.count;
        });
        for (Map.Entry<Integer,Integer> entry : map.entrySet()) {
            if (pq.size() < k) {
                pq.offer(new Node(entry.getKey(),entry.getValue()));
            } else {
                Node n = pq.peek();
                if (entry.getValue() > n.count) {
                    pq.poll();
                    pq.offer(new Node(entry.getKey(),entry.getValue()));
                }
            }
        }
        int[] res = new int[k];
        int index = 0;
        while (!pq.isEmpty()) {
            res[index] = pq.poll().key;
            ++index;
        }
        return res;
    }
}