package L1000;

public class LeetCode1052 {
    public int maxSatisfied1375ms(int[] customers, int[] grumpy, int X) {
        int maxSatisfied = 0;
        for (int i = 0;i < customers.length && i < X;i++){
            maxSatisfied += customers[i];
        }       
        int left = 0;
        int right = X - 1;
        for (int i = X;i < customers.length;i++){
            if (grumpy[i] == 0){
                maxSatisfied += customers[i];
            } else {
                int last = maxSatisfied;
                for (int j = 0;j < i - right;j++){
                    if (grumpy[left + j] == 1){
                        last -= customers[left + j];
                    }               
                }    
                for (int j = right + 1;j <= i;j++){
                    if (grumpy[j] == 1){
                        last += customers[j];
                    }
                }            
                if (last > maxSatisfied){
                    maxSatisfied = last;
                    right = i;
                    left = right - X + 1;
                }
            }
        }
        return maxSatisfied;
    }

    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int max = 0;
        for (int i = 0;i < customers.length;++i) {
            if (grumpy[i] == 0) {
                max += customers[i];
            }
        }
        for (int i = 0;i < X;++i) {
            if (grumpy[i] == 1) {
                max += customers[i];
            }
        }
        int last = max;
        for (int i = 0, j = X;j < customers.length;++j,++i) {
            if (grumpy[i] == 1) {
                last -= customers[i];
            }
            if (grumpy[j] == 1) {
                last += customers[j];
            }
            max = Math.max(last, max);
        }
        return max;
    }
}