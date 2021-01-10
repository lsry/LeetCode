package L200;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0228 {
    public List<String> summaryRanges(int[] nums) {
        List<String> res = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return res;
        }
        int left = nums[0];
        int right = nums[0];
        for (int i = 1;i < nums.length;++i) {
            if (nums[i] == right) {
                continue;
            } else if (nums[i] == right + 1) {
                right = nums[i];
            } else {
                add(res, left, right);
                left = nums[i];
                right = nums[i];
            }
        }
        add(res, left, right);
        return res;
    }

    private void add(List<String> res, int left, int right) {
        if (left == right) {
            res.add(String.valueOf(right));
        } else {
            StringBuilder range = new StringBuilder();
            range.append(left);
            range.append("->");
            range.append(right);
            res.add(range.toString());
        }
    }
}
