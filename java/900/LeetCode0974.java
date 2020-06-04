import java.util.HashMap;

public class LeetCode0974 {
    public int subarraysDivByK(int[] A, int K) {
        if (A == null || A.length == 0) {
            return 0;
        }
        HashMap<Integer,Integer> hii = new HashMap<>();
        hii.put(0, 1);
        int ans = 0, sum = 0;
        for (int i = 0;i < A.length;++i) {
            sum += A[i];
            int mod = (sum % K + K) % K;
            if (hii.containsKey(mod)) {
                ans += hii.get(mod);
            }
            hii.put(mod, hii.getOrDefault(mod, 0) + 1);
        }
        return ans;
    }
}