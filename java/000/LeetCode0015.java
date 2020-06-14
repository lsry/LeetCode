import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode0015 {
    public List<List<Integer>> threeSumBinSearch(int[] nums) { 
        // 1. sorted first       
        Arrays.sort(nums);
        int size = nums.length;
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0;i < size - 2 && nums[i] <= 0;i++){             
            int twoSum = 0 - nums[i];
            int j = i + 1;
            int k = size - 1;
            // 双指针遍历，计算两个指针对应位置和
            while (j < k){
                if (nums[j] + nums[k] == twoSum){
                    List<Integer> ai = new ArrayList<>();
                    ai = Arrays.asList(nums[i], nums[j], nums[k]);
                    if (!result.contains(ai)){  // 判断是否含重复元组
                        result.add(ai);
                    }
                } else if (nums[j] + nums[k] < twoSum){
                    j++;
                } else {
                    k--;
                }
            }
        }
        return result;
    }

    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if (nums == null || nums.length < 3) {
            return res;
        }
        Arrays.sort(nums);
        for (int i = 0;i < nums.length - 2 && nums[i] <= 0;++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int k = nums.length - 1;
            for (int j = i + 1;j < k;++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                while (j < k && nums[i] + nums[j] + nums[k] > 0) {
                    --k;
                }
                if (j >= k) {
                    break;
                }
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                }
            }
        }
        return res;
    }
    
}