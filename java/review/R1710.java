package review;

public class R1710 {
    public int majorityElement(int[] nums) {
        int res = 0;
        int cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {
                res = num;
                ++cnt;
            } else if (num == res) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        cnt = 0;
        for (int num : nums) {
            if (num == res) {
                ++cnt;
            }
        }
        return cnt > nums.length / 2 ? res : -1;
    }
}