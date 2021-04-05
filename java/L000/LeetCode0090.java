package L000;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;

public class LeetCode0090 {
    private List<List<Integer>> res;
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        res = new LinkedList<>();
        res.add(new ArrayList<>());
        if (nums == null || nums.length == 0) {
            return res;
        }
        Arrays.sort(nums);
        List<Integer> path = new ArrayList<>();
        trace(nums, 0, path);
        res.remove(0);  // 前方判空而产生的多余空集，开头总会多出一个空集，
        return res;
    }
    private void trace(int[] nums, int index, List<Integer> path) {
        res.add(new ArrayList<Integer>(path));
        if (index < nums.length) {
            for (int i = index;i < nums.length;++i) {
                if (i > index && nums[i] == nums[i - 1]) {
                    continue;
                }
                path.add(nums[i]);
                trace(nums, i + 1, path);
                path.remove(path.size() - 1);
            }
        }
    }
}
