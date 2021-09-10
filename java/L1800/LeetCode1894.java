package L1800;

public class LeetCode1894 {
    public int chalkReplacer(int[] chalk, int k) {
        long sum = 0;
        for (int c : chalk) {
            sum += c;
        }
        long x = ((long)k) % sum;
        for (int i = 0;i < chalk.length;++i) {
            if (chalk[i] > x) {
                return i;
            }
            x -= chalk[i];
        }
        return -1;
    }
}