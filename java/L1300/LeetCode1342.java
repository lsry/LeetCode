package L1300;

public class LeetCode1342 {
    public int numberOfSteps(int num) {
        int count = 0;
        while (num > 1) {
            count += (num & 1) == 1 ? 2 : 1;
            num = num >>> 1;
        }
        return count + (num == 1 ? 1 : 0);
    }
}
