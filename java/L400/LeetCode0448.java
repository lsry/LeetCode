package L400;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0448 {
    /**
     * 将对应的数字归位
     */
    public List<Integer> findDisappearedNumbersSkip(int[] nums) {
        for (int i = 0;i < nums.length;i++){
            int x = nums[i];
            while (x != 0 && x != -1){
                nums[i] = -1;  // 该数字未出现
                int t = x;
                x = nums[t - 1];
                nums[t - 1] = 0; // 该数字出现过
            }           
        }
        List<Integer> li = new ArrayList<>();
        for (int i = 0;i < nums.length;i++){
            if (nums[i] == -1){
                li.add(i + 1);
            }
        }
        return li;
    }

    /**
     * 由于数字均处于 [1, n], 将数字对应的位置加上 n，代表该数字出现过
     */
    public List<Integer> findDisappearedNumbers(int[] nums) {
        final int n = nums.length;
        for (int i = 0;i < n;i++){
            int p = (nums[i] - 1) % n;
            nums[p] += n;
        }
        List<Integer> li = new ArrayList<>();
        for (int i = 0;i < n;i++){
            if (nums[i] <= n){
                li.add(i + 1);
            }
        }
        return li;
    }

    public static void main(String[] args) {
        
    }
}