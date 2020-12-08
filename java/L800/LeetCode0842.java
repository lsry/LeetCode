package L800;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0842 {
    private List<Integer> res;
    private char[] nums;
    private int N;
    public List<Integer> splitIntoFibonacci(String S) {
        res = new ArrayList<>();
        N = S.length();
        nums = S.toCharArray();
        if (getNum(0)) {
            return res;
        } else {
            return new ArrayList<>();
        }
    }
    private boolean getNum(int index) {
        if (index >= N) {
            return res.size() > 2;
        }
        if (nums[index] == '0') {
            int sz = res.size();
            if (sz > 1 && 0 != res.get(sz - 1) + res.get(sz - 2)) {
                return false;
            }
            res.add(0);
            if(getNum(index + 1)){
                return true;
            } else {
                res.remove(res.size() - 1);
                return false;
            }
        } 
        long value = 0L;
        for (int i = index;i < N;++i) {
            value = value * 10 + nums[i] - '0';
            if (value > Integer.MAX_VALUE) {
                break;
            }
            int sz = res.size();
            if (sz >= 2) {
                long sum = res.get(sz - 1) + res.get(sz - 2);
                if (sum < value) {
                    break;
                } else if (sum > value) {
                    continue;
                } 
            }
            res.add((int)value);
            if (getNum(i + 1)) {
                return true;
            } else {
                res.remove(res.size() - 1);
            }
        }
        return false;
    }

    public static void main(String[] args) {
        LeetCode0842 code = new LeetCode0842();
        code.splitIntoFibonacci("123456579");
    }
}
