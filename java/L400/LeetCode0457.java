package L400;

public class LeetCode0457 {
    public boolean circularArrayLoop(int[] nums) {
        if (nums == null || nums.length < 2) {
            return false;
        }
        final int N = nums.length;
        int offset = 2001;
        int round = 1;
        for (int i = 0;i < N;++i) {
            if (nums[i] <= 1000) {
                boolean neg = nums[i] > 0 ? false : true;
                int nx = i;
                boolean circle = false;
                do {
                    int t = nx;
                    nx = (nx + nums[nx] + N * 1000) % N;
                    if (nums[nx] > 1000 && nums[nx] <= 1000 + offset * (round - 1)) {
                        break;
                    }
                    if (nums[nx] > -1000 + offset * round) {
                        circle = true;
                    }
                    if (nums[nx] < 0 && !neg || nums[nx] > 0 && neg) {
                        break;
                    }
                    nums[t] = nums[t] + offset * round;
                } while (nums[nx] <= 1000);
                if (circle) {
                    int j = (nx + nums[nx] - round * offset + N * 1000) % N;
                    if (j != nx) {
                        return true;
                    }
                }
                ++round;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        LeetCode0457 code = new LeetCode0457();
        code.circularArrayLoop(new int[]{-1,-1,-1});
    }
}