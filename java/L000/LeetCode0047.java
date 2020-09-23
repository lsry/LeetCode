package L000;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode0047 {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        boolean[] mute = new boolean[nums.length];
        dfs(nums, 0, path, res,mute);
        return res;
    }

    private void dfs(int[] nums, int index,List<Integer> path, List<List<Integer>> res,boolean[] mute) {
        if (index >= nums.length) {
            res.add(new ArrayList<>(path));
            return;
        }
        int lastValue = Integer.MAX_VALUE;
        for (int i = 0;i < nums.length;++i) {
            if (nums[i] == lastValue || mute[i]) {
                continue;
            }
            lastValue = nums[i];
            mute[i] = true;
            path.add(nums[i]);
            dfs(nums, index + 1, path, res,mute);
            path.remove(path.size() - 1);
            mute[i] = false;
        }
    }
}
