import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class LeetCode0126{

    public boolean isdiffOne(String one,String two){
        int count = 0;
        for (int i = 0;i < one.length() && count < 2;i++){
            if (one.charAt(i) != two.charAt(i)){
                count++;
            }
        }
        return count == 1;
    }

    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> res = new ArrayList<>();
        int index = 0;
        HashMap<String,Integer> str2Id = new HashMap<>();
        List<String> id2str = new ArrayList<>(wordList.size() + 1);
        str2Id.put(beginWord, index);
        id2str.add(beginWord);
        for (String word : wordList) {
            if (!str2Id.containsKey(word)) {
                ++index;
                str2Id.put(word, index);
                id2str.add(word);
            }
        }
        if (!str2Id.containsKey(endWord)) {
            return res;
        }
        final int wordCount = id2str.size();
        List<List<Integer>> edges = new ArrayList<>(wordCount);        
        for (int i = 0;i < wordCount;++i) {
            edges.add(new ArrayList<>());
        }
        for (int i = 0;i < wordCount;++i) {
            for (int j = i + 1;j < wordCount;++j) {
                if (isdiffOne(id2str.get(i), id2str.get(j))) {
                    edges.get(i).add(j);
                    edges.get(j).add(i);
                }
            }
        }
        Queue<List<Integer>> qu = new LinkedList<>();
        List<Integer> begin = new ArrayList<>();
        begin.add(str2Id.get(beginWord));
        qu.offer(begin);
        int[] cost = new int[wordCount];
        for (int i = 1;i < wordCount;++i) {
            cost[i] = Integer.MAX_VALUE;
        }
        final int dest = str2Id.get(endWord);
        while (!qu.isEmpty()) {
            List<Integer> now = qu.poll();
            if (now.get(now.size() - 1) == dest) {
                List<String> tmp = new ArrayList<>(now.size());
                for (int x : now) {
                    tmp.add(id2str.get(x));
                }
                res.add(tmp);
            } else {
                int cur = now.get(now.size() - 1);
                List<Integer> points = edges.get(cur);
                for (int point : points) {
                    if (cost[point] >= cost[cur] + 1) {
                        List<Integer> tmp = new ArrayList<>(now);
                        tmp.add(point);
                        qu.add(tmp);
                        cost[point] = cost[cur] + 1;
                    }
                }
            }
        }
        return res;
    }
}