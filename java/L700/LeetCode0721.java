package L700;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LeetCode0721 {
    private class UnionFind {
        private int[] ids, ranks;

        public UnionFind(int N) { 
            ids = new int[N];
            ranks = new int[N];
            for (int i = 0;i < N;++i) {
                ids[i] = i;
            }
        }

        public int find(int id) {
            while (ids[id] != id) {
                id = ids[id];
            }
            return id;
        }

        public void union(int p, int q) {
            int pid = find(p);
            int qid = find(q);
            if (pid != qid) {
                if (ranks[pid] <= ranks[qid]) {
                    ids[pid] = qid;
                } else {
                    ids[qid] = pid;
                }
                if (ranks[pid] == ranks[qid]) {
                    ranks[qid] += 1;
                }
            }
        }
    }
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, Integer> emailIndex = new HashMap<>();
        Map<String,String> emailName = new HashMap<>();
        int emailCount = 0;
        for (List<String> account : accounts) {
            String name = account.get(0);
            int sz = account.size();
            for (int i = 1;i < sz;++i) {
                String email = account.get(i);
                if (!emailIndex.containsKey(email)) {
                    emailIndex.put(email, emailCount);
                    ++emailCount;
                    emailName.put(email, name);
                }
            }
        }
        UnionFind uf = new UnionFind(emailCount);
        for (List<String> account : accounts) {
            String firstEmail = account.get(1);
            int sz = account.size();
            for (int i = 2;i < sz;++i) {
                uf.union(emailIndex.get(firstEmail), emailIndex.get(account.get(i)));
            }
        }
        Map<Integer, List<String>> indexEmail = new HashMap<>();
        for (Map.Entry<String, Integer> entry : emailIndex.entrySet()) {
            int id = uf.find(entry.getValue());
            List<String> cur = indexEmail.getOrDefault(id, new ArrayList<>());
            cur.add(entry.getKey());
            indexEmail.put(id, cur);
        }
        List<List<String>> res = new ArrayList<>();
        for (Map.Entry<Integer,List<String>> entry: indexEmail.entrySet()) {
            List<String> emails = entry.getValue();
            Collections.sort(emails);
            List<String> cur = new ArrayList<>();
            cur.add(emailName.get(emails.get(0)));
            for (String email : emails) {
                cur.add(email);
            }
            res.add(cur);
        }
        return res;
    }
}
