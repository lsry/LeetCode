package L500;

import java.util.HashMap;

public class LeetCode0560{
    /**
     * 使用前缀和，省了一次内部循环
     */
    public int subarraySum1(int[] nums, int k) {
        int[] arr =new int[nums.length];
        arr[0] = nums[0];
        for (int i = 1;i < nums.length;i++){
            arr[i] = arr[i-1] + nums[i];
        }

        int count = 0;
        for (int i = 0;i < arr.length;i++){
            for (int j = i;j < arr.length;j++){
                if (arr[j] - arr[i] + nums[i] == k){
                    count++;
                }
            }
        }
        return count;
    }

    /**
     * 记录前缀和
     * pre[i - 1] = pre[j] - K, 查找 i-1 的存在性
     */
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        HashMap<Integer,Integer> hii = new HashMap<>();
        hii.put(0, 1);
        int pre = 0;
        // 每一个元素时，以该元素为后缀，通过哈希表查找前面是否存在等于差值的前缀和
        for (int i = 0;i < nums.length;i++){
            pre += nums[i];
            int diff = pre - k;
            if (hii.containsKey(diff)){
                count += hii.get(diff);
            } 
            hii.put(pre, hii.getOrDefault(pre, 0) + 1);
        }
        return count;
    }

    public static void main(String[] args) {
        
    }
}