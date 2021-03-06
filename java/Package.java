/**
 * 状态定义：dp[i][j]表示从数组的 [0, i] 这个子区间内挑选一些正整数，每个数只能用一次，使得这些数的和恰好等于 j
 * dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i]]
 */
public class Package {
    public Package(){}

    public void package01() {
        int n = 5, C = 10;
        int[] value = new int[]{6,3,5,4,6};
        int[] weight = new int[]{2,2,6,5,4};
        int[][] arr = new int[n + 1][C + 1];
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= C;j++){
                if (weight[i - 1] > j){
                    arr[i][j] = arr[i-1][j];
                } else {
                    arr[i][j] = Math.max(arr[i-1][j], value[i-1] + arr[i-1][j-weight[i-1]]);
                }
            }
        }
        System.out.println(arr[n][C]);
    }

    public void package01SpaceFree() {
        int n = 5, C = 10;
        int[] value = new int[]{6,3,5,4,6};
        int[] weight = new int[]{2,2,6,5,4};
        int[] arr = new int[C + 1];
        for (int i = 1;i <= n;i++){
            // 采用逆序
            for (int j = C;j - weight[i - 1] >= 0;j--){
                int curValue = value[i-1] + arr[j - weight[i-1]];
                if (curValue > arr[j]){
                    arr[j] = curValue;
                }
            }
        }
        System.out.println(arr[C]);
    }

    public static void main(String[] args) {
        Package packag = new Package();
        packag.package01SpaceFree();
    }
}