package L400;

public class LeetCode0459 {
    public boolean repeatedSubstringPatternDoubleIter(String s) {
        String sub = "";
        final int N = s.length();
        for (int i = 1;2 * i <= N;i++){
            if (N % i != 0) {
                continue;
            }
            sub = s.substring(0, i);
            int j = i;
            while (j + i <= N){
                if (!sub.equals(s.substring(j, j + i))){
                    break;
                }
                j += i;
            }
            if (j >= N){
                return true;
            }
        }
        return false;
    }

    public boolean repeatedSubstringPattern(String s) {
        int index = (s + s).indexOf(s, 1);
        return index != -1 && index != s.length();
    }
}