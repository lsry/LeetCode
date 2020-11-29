package L100;

public class LeetCode0164 {
    public int maximumGap(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return 0;
        }
        int min = Integer.MAX_VALUE, max = 0;
        for (int n : nums) {
            min = Math.min(min, n);
            max = Math.max(max, n);
        }
        final int N = nums.length;
        int d = Math.max(1, (max - min) / (N - 1));
        int size = (max - min) / d + 1;
        int[][] bucket = new int[size][2];
        for (int i = 0;i < size;++i) {
            bucket[i][0] = bucket[i][1] = -1;
        }
        for (int num : nums) {
            int id = (num - min) / d;
            if (bucket[id][0] == -1) {
                bucket[id][0] = num;
                bucket[id][1] = num;
            } else {
                bucket[id][0] = Math.min(bucket[id][0], num);
                bucket[id][1] = Math.max(bucket[id][1], num);
            }
        }
        int ans = 0;
        int last = bucket[0][1];
        for (int i = 1;i < size;++i) {
            if (bucket[i][0] != -1) {
                ans = Math.max(ans, bucket[i][0] - last);
                last = bucket[i][1];
            }
            
        }
        return ans;
    }

    public static void main(String[] args) {
        LeetCode0164 code = new LeetCode0164();
        code.maximumGap(new int[]{1,3,6,9});
    }
}
