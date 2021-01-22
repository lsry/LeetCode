package L1200;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LeetCode1202 {
    private int[] indics;
    private int[] ranks;

    public int find(int id) {
        while (indics[id] != id) {
            id = indics[id];
        }
        return id;
    }

    public void union(int p, int q) {
        int pid = find(p);
        int qid = find(q);
        if (pid != qid) {
            if (ranks[pid] >= ranks[qid]) {
                indics[qid] = pid;
            } else {
                indics[pid] = qid;
            }
            if (ranks[pid] == ranks[qid]) {
                ranks[pid] += 1;
            }
        }
    }

    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        if (s == null || s.length() < 2 || pairs.size() == 0) {
            return s;
        } 
        final int N = s.length();
        indics = new int[N];
        ranks = new int[N];
        for (int i = 0;i < N;++i) {
            indics[i] = i;
            ranks[i] = 1;
        }
        for (List<Integer> pair : pairs) {
            union(pair.get(0), pair.get(1));
        }
        HashMap<Integer,List<Integer>> map = new HashMap<>();
        for (int index = 0;index < N;++index) {
            int id = find(index);
            List<Integer> cur = map.getOrDefault(id, new ArrayList<>());
            cur.add(index);
            map.put(id, cur);
        }
        char[] sch = s.toCharArray();
        for (Map.Entry<Integer,List<Integer>> entry : map.entrySet()) {
            List<Integer> cur = entry.getValue();
            List<Character> chs = new ArrayList<>(cur.size());
            for (int id : cur) {
                chs.add(sch[id]);
            }
            Collections.sort(chs);
            for (int i = 0;i < cur.size();++i) {
                sch[cur.get(i)] = chs.get(i);
            }
        }
        return String.valueOf(sch);
    }
}
