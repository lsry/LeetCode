package L300;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;

public class LeetCode0399 {
    private double[] res;
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        res = new double[queries.size()];
        HashMap<String, HashMap<String, Double>> grap = new HashMap<>();
        for (int i = 0;i < values.length;++i) {
            List<String> cur = equations.get(i);
            String d1 = cur.get(0);
            String d2 = cur.get(1);
            HashMap<String, Double> fMap = grap.getOrDefault(d1, new HashMap<>());
            fMap.put(d2, values[i]);
            grap.put(d1, fMap);
            fMap = grap.getOrDefault(d2, new HashMap<>());
            fMap.put(d1, 1.0 / values[i]);
            grap.put(d2, fMap);
        }
        HashSet<String> flags = new HashSet<>();
        int i = 0;
        for (List<String> query : queries) {
            String d1 = query.get(0);
            String d2 = query.get(1);
            search(d1, d2, grap, flags, i);
            ++i;
        }
        return res;
    }

    private boolean search(String d1, String d2, HashMap<String, HashMap<String, Double>> grap, HashSet<String> flags, int i) {
        if (!grap.containsKey(d1) && !grap.containsKey(d2)) {
            res[i] = -1.0;
            return false;
        }
        HashMap<String, Double> fmap = grap.getOrDefault(d1, new HashMap<>());
        if (fmap.containsKey(d2)) {
            res[i] = fmap.get(d2);
            return true;
        }
        flags.add(d1);
        for (Map.Entry<String,Double> entry: fmap.entrySet()) {
            String next = entry.getKey();
            if (!flags.contains(next) && search(entry.getKey(), d2, grap, flags, i)) {
                res[i] = entry.getValue() * res[i];
                flags.remove(d1);
                return true;
            }
        }
        flags.remove(d1);
        res[i] = -1.0;
        return false;
    }
}
