package L600;

public class LeetCode0645 {
    public int[] findErrorNums(int[] nums) {
       int[] temp = new int[nums.length];
       for (int t : nums) {
           temp[t - 1]++;
       } 
       int[] res = new int[2];
       for (int i = 0;i < temp.length;++i) {
            if (temp[i] == 2) {
                res[0] = i + 1;
            } else if (temp[i] == 0) {
                res[1] = i + 1;
            }
       }
       return res;
    }
}