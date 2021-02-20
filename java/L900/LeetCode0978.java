package L900;

public class LeetCode0978 {
    public int maxTurbulenceSizeDivid(int[] A) {
        return helper(A,0,A.length-1);
    }

    public int helper(int[] A,int head,int tail){
        if (head == tail || (head + 1 == tail && A[head] == A[tail])){
            return 1;
        } else if (head + 1 == tail){
            return 2;
        }
        int next = head + 1;
        while (next < tail){
            int f = A[next - 1];
            int m = A[next];
            int b = A[next + 1];
            if ((f < m && m > b) || (f > m && m < b)){
                next++;
            } else {
                break;
            }
        }
        if (next == tail){
            return tail - head + 1;
        } else {
            int left = helper(A,head,next);
            int right = helper(A,next,tail);
            return left > right ? left : right;
        }
    }

    public int maxTurbulenceSize(int[] arr) {
        if (arr.length < 2) {
            return arr.length;
        } else if (arr.length == 2) {
            return arr[0] != arr[1] ? 2 : 1;
        }
        int len = 1;
        int i = 0, j = 2;
        // TODO：可考虑 j 从 1开始 0 < j < n - 1
        for (;j < arr.length;++j) {
            if ((arr[j] >= arr[j - 1] && arr[j - 1] > arr[j - 2]) || (arr[j] <= arr[j - 1] && arr[j - 1] < arr[j - 2])) {
                if (arr[j - 1] == arr[j - 2]) {
                    len = Math.max(len, 1);
                    i = j;
                } else {
                    len = Math.max(len, j - i);
                    i = arr[j] == arr[j - 1] ? j : j - 1;
                }
            }
        }
        if (arr[j - 1] != arr[j - 2]) {
            len = Math.max(len, j - i);
        }
        
        return len;
    }
}