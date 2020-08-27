import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class LeetCode0491 {
    public List<List<Integer>> findSubsequences(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0;i < nums.length - 1;++i) {
            if (set.contains(nums[i])) {
                continue;
            }
            set.add(nums[i]);
            List<Integer> cList = new ArrayList<>();
            cList.add(nums[i]);
            helper(res, cList, nums, i + 1);
        }
        return res;
    }

    private void helper(List<List<Integer>> res, List<Integer> cList,int[] nums, int index) {
        if (index >= nums.length) {
            return;
        }
        HashSet<Integer> set = new HashSet<>();
        for (int i = index;i < nums.length;++i) {
            if (set.contains(nums[i]) || nums[i] < cList.get(cList.size() - 1)) {
                continue;
            }
            set.add(nums[i]);
            List<Integer> cur = new ArrayList<>(cList);
            cur.add(nums[i]);
            res.add(cur);
            helper(res, cur, nums, i + 1);
        }
    }
}