package L500;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class LeetCode0526 {
    private int count = 0;

    // 存储每一个位置满足要求的所有解
    private List<Set<Integer>> availe = new ArrayList<>();

    /**
     * 回溯计算
     */
    public int countArrangementTrace(int N) {  
        for (int i = 1;i <= N;i++){
            Set<Integer> si = new HashSet<>();
            for (int j = 1;j <= N;j++){
                if (judge(i, j)){
                    si.add(j);
                }
            }
            availe.add(si);
        }

        int[] arr = new int[N];
        helper(arr, 1, N);
        return count;
    }

    public void helper(int[] arr,int index,int N){
        if (index > N){
            return;
        }
        Set<Integer> si = availe.get(index - 1);
        for (Integer i : si){
            if (arr[i - 1] == 1){ // 优化点：=1 代表该数已经用过，没必要再往下验证了
                continue;
            } else {
                arr[i - 1] = 1;
                if (index == N && valid(arr)){
                    count++;
                } else {
                    helper(arr, index + 1, N);
                }
                arr[i - 1] = 0;
            }  
        }
    }

    public boolean judge(int sou,int tar){
        return (sou % tar == 0 || tar % sou == 0);
    }

    public boolean valid(int[] arr){
        for (int a : arr){
            if (a == 0){
                return false;
            }
        }
        return true;
    }

    public int countArrangement(int n) {
        int mask = 1 << n;
        int[] dp = new int[mask];
        dp[0] = 1;
        for (int state = 1;state < mask;++state) {
            int cnt = Integer.bitCount(state);
            for (int i = 0;i < n;++i) {
                if (((state >> i) & 1) == 0) {
                    continue;
                }
                if ((i + 1) % cnt != 0 && cnt % (i + 1) != 0) {
                    continue;
                }
                dp[state] += dp[state & (~(1 << i))];
            }
        }
        return dp[mask - 1];
    }
}