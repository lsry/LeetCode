package L900;

import java.util.HashMap;

public class LeetCode0992 {
    public int subarraysWithKDistinct(int[] A, int K) {
        return subarraysWithLessThanKDistinct(A, K) - subarraysWithLessThanKDistinct(A, K - 1);
    }

    public int subarraysWithLessThanKDistinct(int[] A, int K) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int i = 0, j = 0;
        int diff = 0;
        int ans = 0;
        for (;j < A.length;++j) {
            map.put(A[j], map.getOrDefault(A[j], 0) + 1);
            if (map.get(A[j]) == 1) {
                ++diff;
            }
            if (diff > K) {
                while (diff > K) {
                    map.put(A[i], map.get(A[i]) - 1);
                    if (map.get(A[i]) == 0) {
                        --diff;
                    }
                    ++i;
                }
            }
            ans += j - i + 1;
        }
        return ans;
    }
}
