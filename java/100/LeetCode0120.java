import java.util.List;

public class LeetCode0120 {
    public int minimumTotal_7ms(List<List<Integer>> triangle) {
        if (triangle == null || triangle.size() == 0) {
            return 0;
        }
        List<Integer> cur = triangle.get(triangle.size() - 1);
        for (int i = triangle.size() - 2;i >= 0;--i) {
            cur = triangle.get(i);
            List<Integer> next = triangle.get(i + 1);
            for (int j = 0;j < cur.size();++j) {
                cur.set(j, cur.get(j) + Math.min(next.get(j),next.get(j + 1)));
            }
        }
        return cur.get(0);
    }

    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null || triangle.size() == 0) {
            return 0;
        }
        int[] res = triangle.get(triangle.size() - 1).stream().mapToInt(k->k).toArray();
        for (int i = triangle.size() - 2;i >= 0;--i) {
            List<Integer> cur = triangle.get(i);
            for (int j = 0;j < cur.size();++j) {
                res[j] = cur.get(j) + Math.min(res[j], res[j + 1]);
            }
        }
        return res[0];
    }
}