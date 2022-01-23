package L300;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode0373 {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        boolean flag = true;
        if (nums1.length > nums2.length) {
            int[] num = nums1;
            nums1 = nums2;
            nums2 = num;
            flag = false;
        }
        List<List<Integer>> res = new ArrayList<>(k);
        int[] indics = new int[nums1.length];
        int target = Math.min(nums1.length * nums2.length, k);
        int index = 0;
        while (target > 0 && index < indics.length) {
            if (indics[index] >= nums2.length) {
                ++index;
            }
            int minIndex = index;
            int a = nums1[index], b = nums2[indics[index]];
            for (int i = index + 1;i < nums1.length;++i) {
                if (nums1[i] + nums2[indics[i]] < a + b) {
                    a = nums1[i];
                    b = nums2[indics[i]];
                    minIndex = i;
                }
            }
            if (flag) {
                res.add(Arrays.asList(a, b));
            } else {
                res.add(Arrays.asList(b, a));
            }
            indics[minIndex]++;
            --target;
        }
        return res;
    }

    public static void main(String[] args) {
        LeetCode0373 code = new LeetCode0373();
        code.kSmallestPairs(new int[]{0,0,0,0,0}, new int[]{-3,22,35,56,76}, 22);
    }
}
