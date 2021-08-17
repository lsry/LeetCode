import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LeetCode0446 {
    public int numberOfArithmeticSlices(int[] nums) {
        if (nums == null || nums.length < 3) {
            return 0;
        }
        final int N = nums.length;
        List<HashMap<Long,Integer>> mapList = new ArrayList<>(N);
        for (int i = 0;i < N;++i) {
            mapList.add(new HashMap<>());
        }
        for (int i = 1;i < N;++i) {
            HashMap<Long,Integer> curMap = mapList.get(i);
            for (int j = i - 1;j >= 0;--j) {
                long d = nums[i] * 1L - nums[j];
                HashMap<Long,Integer> map = mapList.get(j);
                int x = map.getOrDefault(d, 0) + 1;
                curMap.put(d, x + curMap.getOrDefault(d, 0));
            }
        }
        int ans = 0;
        for (HashMap<Long,Integer> map : mapList) {
            for (Map.Entry<Long,Integer> entry : map.entrySet()) {
                ans += entry.getValue();
            }
        }
        return ans - (N - 1) * N / 2;
    }
}
