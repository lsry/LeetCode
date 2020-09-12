package L200;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0216 {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>(k);
        dfs(res, path, k, n, 1);
        return res;
    }

    private void dfs(List<List<Integer>> res, List<Integer> path, int k, int n, int index) {
        if (k < 0 || n < 0) {
            return;
        }
        if (k == 0) {
            if (n == 0) {
                res.add(new ArrayList<>(path));
            }
            return;
        }
        for (int i = index;i < 10;++i) {
            if (n - i < 0) {
                break;
            }
            path.add(i);
            dfs(res, path, k - 1, n - i, i + 1);
            path.remove(path.size() - 1);
        }
    }
}
