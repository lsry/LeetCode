package L600;

public class LeetCode0679 {
    private static final double EPLSION = 1e-6;
    private static final double TARGET = 24.0;
    public boolean judgePoint24(int[] nums) {
        double[] dnums = new double[4];
        for (int i = 0;i < nums.length;++i) {
            dnums[i] = (double)nums[i];
        }
        return helper(dnums);
    }

    private boolean helper(double[] dnums) {
        if (dnums.length == 2) {
            return Math.abs(dnums[0] + dnums[1] - TARGET) <= EPLSION ||
                   Math.abs(dnums[0] - dnums[1] - TARGET) <= EPLSION ||
                   Math.abs(dnums[1] - dnums[0] - TARGET) <= EPLSION ||
                   Math.abs(dnums[0] * dnums[1] - TARGET) <= EPLSION ||
                   (Math.abs(dnums[1]) > EPLSION && Math.abs(dnums[0] / dnums[1] - TARGET) < EPLSION) ||
                   (Math.abs(dnums[0]) > EPLSION && Math.abs(dnums[1] / dnums[0] - TARGET) < EPLSION);
        }
        for (int i = 0;i < dnums.length;++i) {
            for (int j = i + 1;j < dnums.length;++j) {
                double[] tmp = new double[dnums.length - 1];
                int index = 0;
                for (int k = 0;k < dnums.length;++k) {
                    if (k != i && k != j) {
                        tmp[index] = dnums[k];
                        ++index;
                    }
                }
                tmp[index] = dnums[i] + dnums[j];
                if (helper(tmp)) {
                    return true;
                }
                tmp[index] = dnums[i] - dnums[j];
                if (helper(tmp)) {
                    return true;
                }
                tmp[index] = dnums[j] - dnums[i];
                if (helper(tmp)) {
                    return true;
                }
                tmp[index] = dnums[i] * dnums[j];
                if (helper(tmp)) {
                    return true;
                }
                if (Math.abs(dnums[j]) > EPLSION) {
                    tmp[index] = dnums[i] / dnums[j];
                    if (helper(tmp)) {
                        return true;
                    }
                }
                if (Math.abs(dnums[i]) > EPLSION) {
                    tmp[index] = dnums[j] / dnums[i];
                    if (helper(tmp)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}