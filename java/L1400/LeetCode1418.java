package L1400;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

public class LeetCode1418 {
    public List<List<String>> displayTable(List<List<String>> orders) {
        if (orders == null || orders.size() == 0) {
            return new ArrayList<>();
        }
        List<HashMap<String, Integer>> res = new ArrayList<>(502);
        for (int i = 0;i < 502;++i) {
            res.add(new HashMap<>());
        }
        HashSet<String> dishes = new HashSet<>();
        for (List<String> order : orders) {
            int table = Integer.valueOf(order.get(1));
            String dish = order.get(2);
            dishes.add(dish);
            HashMap<String, Integer> tableDish = res.get(table);
            tableDish.put(dish, tableDish.getOrDefault(dish, 0) + 1);
        }
        List<String> title = new ArrayList<>(dishes);
        Collections.sort(title);
        title.add(0, "Table");
        List<List<String>> dishExp = new ArrayList<>();
        dishExp.add(title);
        int N = title.size();
        for (int i = 0;i < res.size();++i) {
            HashMap<String, Integer> map = res.get(i);
            if (map.size() > 0) {
                List<String> tmp = new ArrayList<>();
                tmp.add(String.valueOf(i));
                for (int j = 1;j < N;++j) {
                    String dish = title.get(j);
                    tmp.add(String.valueOf(map.getOrDefault(dish, 0)));
                }
                dishExp.add(tmp);
            }
        }
        return dishExp; 
    }
}