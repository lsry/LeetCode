package L800;

public class LeetCode0810 {
    public boolean xorGame(int[] nums) {
        if (nums.length % 2 == 0) {
            return true;
        }
        int x = 0;
        for (int num : nums) {
            x = x ^ num;
        }
        return x == 0;
    }
}
