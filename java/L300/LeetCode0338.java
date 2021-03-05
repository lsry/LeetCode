package L300;

public class LeetCode0338 {
    public int[] countBits(int num) {
        if (num == 0) {
            return new int[]{0};
        } else if (num == 1) {
            return new int[]{0, 1};
        }
        int[] res = new int[num + 1];
        res[1] = 1;
        for (int i = 1;i <= num;i *= 2) {
            for (int j = 0;j < i && i + j <= num;++j) {
                res[i + j] = 1 + res[j];
            }
        }
        return res;
    }
}
