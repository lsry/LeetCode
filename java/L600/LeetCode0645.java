package L600;

public class LeetCode0645 {
    /**
     * 统计每个数字出现的次数
     * 2：重复
     * 0：消失
     */
    public int[] findErrorNumsCount(int[] nums) {
       int[] temp = new int[nums.length];
       for (int t : nums) {
           temp[t - 1]++;
       } 
       int[] res = new int[2];
       for (int i = 0;i < temp.length;++i) {
            if (temp[i] == 2) {
                res[0] = i + 1;
            } else if (temp[i] == 0) {
                res[1] = i + 1;
            }
       }
       return res;
    }

    /**
     * 桶排序
     * 将数字放到对应的位置上去
     */
    public int[] findErrorNums(int[] nums) {
        final int N = nums.length;
        for (int i = 0;i < N;++i) {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                int t = nums[i];
                nums[i] = nums[nums[i] - 1];
                nums[t - 1] = t; // 这里 t 不能是 nums[i], 因为上一条语句改变了值
            }
        }
        for (int i = 0;i < N;++i) {
            if (nums[i] != i + 1) {
                return new int[]{nums[i], i + 1};
            }
        }
        return new int[]{-1, -1};
    }

    public static void main(String[] args) {
        LeetCode0645 code = new LeetCode0645();
        code.findErrorNums(new int[]{3,2,2});
    }
}