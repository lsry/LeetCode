package L100;

public class LeetCode0189 {
    public void rotate(int[] nums, int k) {
        final int N = nums.length;
        k = k % N;
        if (N < 2 || k == 0) {
            return;
        }
        int t = 1;
        for (int a = 0;a < k;++a) {
            int v = nums[a];
            int i = a;           
            do {
                int i1 = (i + k) % N;
                int v1 = nums[i1];
                nums[i1] = v;
                v = v1;
                i = i1;
                ++t;
            } while (i != a);
            if (t >= N) {
                break;
            }
        }
    }
}
