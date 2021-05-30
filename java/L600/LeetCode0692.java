package L600;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class LeetCode0692 {
    public List<String> topKFrequent(String[] words, int k) {
        List<String> res = new ArrayList<>(k);
        if (words == null || words.length == 0) {
            return res;
        }
        HashMap<String,Integer> map = new HashMap<>();
        for (String word : words) {
            map.put(word, map.getOrDefault(word, 0) + 1);
        }
        PriorityQueue<String> pq = new PriorityQueue<>((a, b) -> {
            if (map.get(a) != map.get(b)) {
                return map.get(a) - map.get(b);
            } else {
                return b.compareTo(a);
            }
        });
        for (Map.Entry<String,Integer> entry : map.entrySet()) {
            if (pq.size() < k) {
                pq.offer(entry.getKey());
            } else if (map.get(pq.peek()) < entry.getValue()) {
                pq.poll();
                pq.offer(entry.getKey());
            } else if ((map.get(pq.peek()).equals(entry.getValue())) && (entry.getKey().compareTo(pq.peek()) < 0)) {
                pq.poll();
                pq.offer(entry.getKey());
            }
        }
        while (!pq.isEmpty()) {
            res.add(pq.poll());
        }
        Collections.sort(res, (a, b) -> {
            if (map.get(a) != map.get(b)) {
                return map.get(b) - map.get(a);
            } else {
                return a.compareTo(b);
            }
        });
        return res;
    }
}
