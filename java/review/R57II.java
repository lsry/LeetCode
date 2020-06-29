package review;

import java.util.ArrayList;
import java.util.List;

public class R57II {
    /**
     * 双指针遍历
     */
    public int[][] findContinuousSequence(int target) {
        if (target < 3) {
            return new int[][]{};
        }
        List<int[]> lar = new ArrayList<>();
        int start = 1, end = 2;
        int sum = 1;
        while (start < target) {
            if (sum < target) {
                sum += end;
                end++;               
            } else if (sum > target) {
                sum -= start;
                start++;                
            } else {
                int[] ar = new int[end - start];
                for (int i = start;i < end;++i) {
                    ar[i - start] = i;
                }
                lar.add(ar);
                sum -= start;
                start++;
                
            }
        }
        int[][] arr = new int[lar.size()][];
        int index = 0;
        for (int[] ar : lar) {
            arr[index] = ar;
            ++index;
        }
        return arr;
    }

    public static void main(String[] args) {
        R57II r = new R57II();
        r.findContinuousSequence(15);
    }
}