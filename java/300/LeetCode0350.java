import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

public class LeetCode0350 {
    public int[] intersect(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            return intersect(nums2, nums1);
        }
        if (nums1.length == 0) {
            return new int[]{};
        }
        HashMap<Integer,Integer> hii = new HashMap<>();
        for (int num : nums1) {
            hii.put(num, hii.getOrDefault(num, 0) + 1);
        }
        List<Integer> li = new ArrayList<>(nums1.length);
        for (int num : nums2) {
            if (hii.containsKey(num) && hii.get(num) > 0) {
                li.add(num);
                hii.put(num, hii.get(num) - 1);
            }
        }
        int[] res = new int[li.size()];
        int i = 0;
        for (int n : li) {
            res[i] = n;
            ++i;
        }
        return res;
    }
}