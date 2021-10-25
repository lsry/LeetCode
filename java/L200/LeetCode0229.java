package L200;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0229 {
    public List<Integer> majorityElement(int[] nums) {
        int av = Integer.MIN_VALUE, ac = 0;
        int bv = Integer.MIN_VALUE, bc = 0;
        for (int num : nums) {
            if (num == av) {
                ++ac;
            } else if (num == bv) {
                ++bc;
            } else if (ac == 0) {
                av = num;
                ac = 1;
            } else if (bc == 0) {
                bv = num;
                bc += 1;
            } else {
                --ac;
                --bc;
            }
        }
        ac = 0;
        bc = 0;
        List<Integer> res = new ArrayList<>();
        for (int num : nums) {
            if (num == av) {
                ++ac;
            } else if (num == bv) {
                ++bc;
            }
        }
        if (ac > nums.length / 3) {
            res.add(av);
        }
        if (bc > nums.length / 3) {
            res.add(bv);
        }
        return res;
    }
}