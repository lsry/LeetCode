package L000;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0046 {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        boolean[] visit = new boolean[nums.length];
        List<Integer> cur = new ArrayList<>();
        trace(res,visit,cur,nums);
        return res;
    }

    private void trace(List<List<Integer>> res,boolean[] visit,List<Integer> cur,int[] nums) {
        if (cur.size() == nums.length) {
            res.add(new ArrayList<>(cur));
        } else {
            for (int i = 0;i < nums.length;++i) {
                if (!visit[i]) {
                    cur.add(nums[i]);
                    visit[i] = true;
                    trace(res, visit, cur, nums);
                    visit[i] = false;
                    cur.remove(cur.size() - 1);
                }
            }
        }
    }
}