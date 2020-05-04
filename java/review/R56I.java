public class R56I {
    public int[] singleNumbers(int[] nums) {
        int[] res = new int[2];
        int xor = 0;
        for (int n : nums) {
            xor = xor ^ n;
        }
        int div = 1;
        while ((xor & div) == 0) {
            div =  div << 1;
        }
        for (int num : nums) {
            if ((num & div) == 0) {
                res[0] ^= num;
            } else {
                res[1] ^= num;
            }
        }
        return res;
    }
}