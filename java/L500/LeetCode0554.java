package L500;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LeetCode0554 {
    public int leastBricks(List<List<Integer>> wall) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for (List<Integer> row : wall) {
            int sum = 0;
            int sz = row.size();
            for (int i = 0;i < sz - 1;++i) { // 不应该包括最末尾的边缘
                sum += row.get(i);
                map.put(sum, map.getOrDefault(sum, 0) + 1);
            }
        }
        int max = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            max = Math.max(max, entry.getValue());
        }
        return wall.size() - max;
    }
}
