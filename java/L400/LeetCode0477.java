package L400;

/**
 * 由于每一位只有 0 或 1 两种情况，可以对每一位计算出 0 和 1 的出现次数，然后排列出不同的情况；
 */
public class LeetCode0477 {
    public int totalHammingDistanceString(int[] nums) {
        String[] bins = new String[nums.length];
        for (int i = 0;i < nums.length;i++){
            bins[i] = new StringBuilder(Integer.toBinaryString(nums[i])).reverse().toString();
        }
        int distance = 0;
        for (int i = 0;i < 32;i++){
            int ones = 0;
            for (int j = 0;j < nums.length;j++){
                if (i < bins[j].length() && bins[j].charAt(i) == '1'){
                    ones++;
                }
            }
            distance += ones * (nums.length - ones);
        }
        return distance; 
    }

    public int totalHammingDistance(int[] nums) {
        final int N = nums.length;
        int total = 0;
        for (int i = 0;i < 32;++i) {
            int ones = 0;
            for (int num : nums) {
                if (((num >>> i) & 1) == 1) {
                    ++ones;
                }
            }
            total += ones * (N - ones);
        }
        return total;
    }

    public static void main(String[] args) {
        for (int i = 10;i < 20;i++){
            System.out.println(Integer.toBinaryString(i));
        }
        System.out.println(Integer.toBinaryString((int)Math.pow(10, 9)));
        System.out.println(Integer.toBinaryString(Integer.MAX_VALUE).length());
        System.out.println(Integer.toBinaryString(Integer.MIN_VALUE).length());
    }
}