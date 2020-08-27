import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.PriorityQueue;

public class LeetCode0332 {
    private List<String> res;
    public List<String> findItinerary(List<List<String>> tickets) {
        HashMap<String,PriorityQueue<String>> travle = new HashMap<>();
        for (List<String> ticket : tickets) {
            PriorityQueue<String> qu = travle.get(ticket.get(0));
            if (qu == null) {
                qu = new PriorityQueue<>((s1, s2) -> {
                    return s1.compareTo(s2);
                });
            }
            qu.offer(ticket.get(1));
            travle.put(ticket.get(0), qu);
        }
        res = new ArrayList<>(tickets.size() + 1);
        dfs(travle, "JFK");
        Collections.reverse(res);
        return res;
    }
    private void dfs(HashMap<String,PriorityQueue<String>> travle,String cur) {
        while (travle.containsKey(cur) && travle.get(cur).size() > 0) {
            String next = travle.get(cur).poll();
            dfs(travle, next);
        }
        res.add(cur);
    }
}