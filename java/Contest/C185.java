package Contest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

public class C185 {
    public String reformat(String s) {
        if (s == null || s.length() == 0) {
            return "";
        } else if (s.length() == 1) {
            return s;
        }
        Queue<Character> nums = new LinkedList<>();
        Queue<Character> alphs = new LinkedList<>();
        for (char c : s.toCharArray()) {
            if (c >= '0' && c <= '9') {
                nums.offer(c);
            } else {
                alphs.offer(c);
            }
        }
        StringBuilder res = new StringBuilder();
        if (nums.size() >= alphs.size()) {
            while (!nums.isEmpty() && !alphs.isEmpty()) {
                res.append(nums.poll());
                res.append(alphs.poll());
            }
        } else {
            while (!nums.isEmpty() && !alphs.isEmpty()) {                
                res.append(alphs.poll());
                res.append(nums.poll());
            }
        }
        while (!nums.isEmpty() && !alphs.isEmpty()) {
            res.append(nums.poll());
            res.append(alphs.poll());
        }
        if (nums.isEmpty()) {
            char c = res.length() == 0 ? '0' : res.charAt(res.length() - 1);
            if (c >= '0' && c <= '9' && !alphs.isEmpty()) {
                res.append(alphs.poll());
            }
        }
        if (alphs.isEmpty()) {
            char c = res.length() == 0 ? 'a' : res.charAt(res.length() - 1);
            if (c >= 'a' && c <= 'z' && !nums.isEmpty()) {
                res.append(nums.poll());
            }
        }
        return (nums.isEmpty() && alphs.isEmpty()) ? res.toString() : "";
    }

    public List<List<String>> displayTable(List<List<String>> orders) {
        Set<String> dishes = new HashSet<>();
        Map<Integer,Map<String,Integer>> tables = new HashMap<>();
        for (List<String> order : orders) {
            int tn = Integer.valueOf(order.get(1));
            Map<String,Integer> table = tables.getOrDefault(tn, new HashMap<>());
            String dish = order.get(2);
            dishes.add(dish);
            table.put(dish, table.getOrDefault(dish, 0) + 1);
            tables.put(tn, table);
        }
        List<List<String>> res = new LinkedList<>();
        List<String> fline = new ArrayList<>();
        List<String> dishes2 = new ArrayList<>(dishes);
        Collections.sort(dishes2,(s1,s2) -> {
            return s1.compareTo(s2);
        });
        fline.add("Table");
        for (String dish : dishes2) {
            fline.add(dish);
        }
        for (Map.Entry<Integer,Map<String,Integer>> entry : tables.entrySet()) {
            List<String> cur = new ArrayList<>();
            cur.add(String.valueOf(entry.getKey()));
            for (String dish : dishes2) {
                cur.add(String.valueOf(entry.getValue().getOrDefault(dish, 0)));
            }
            res.add(cur);
        }
        Collections.sort(res,(a,b) -> {
            int an = Integer.valueOf(a.get(0));
            int bn = Integer.valueOf(b.get(0));
            return an - bn;
        });
        res.add(0, fline);
        return res;
    }

    // TLE
    public int minNumberOfFrogsTLE(String croakOfFrogs) {
        if (croakOfFrogs == null || croakOfFrogs.length() == 0) {
            return 0;
        } else if (croakOfFrogs.length() <= 4) {
            return -1;
        }
        int nums = 0;
        StringBuilder sb = new StringBuilder(croakOfFrogs);
        char[] ring = new char[]{'c','r','o','a','k'};
        while (sb.length() >= 5) {
            ++nums;
            StringBuilder another = new StringBuilder();
            int index = 0;
            for (int i = 0;i < sb.length();++i) {
                char c = sb.charAt(i);
                if (c == ring[index]) {
                    index = (index + 1) % 5;
                } else {
                    another.append(c);
                }
            }
            if (index != 0) {
                break;
            }
            sb = another;
        }
        return sb.length() == 0 ? nums : -1;
    }
}