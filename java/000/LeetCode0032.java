import java.util.Stack;

public class LeetCode0032{
    public int longestValidParenthesesStack(String s) {
        if (s == null || s.length() <= 0){
            return 0;
        }
        Stack<Integer> si = new Stack<>();
        si.push(-1); // 栈中存上一次未匹配的右括号索引
        int max = 0;
        for (int i = 0; i < s.length();i++){
            char c = s.charAt(i);
            if (c == '('){
                si.push(i);
            } else {
                si.pop();
                if (si.empty()){
                    si.push(i);
                } else {
                    max = Math.max(max, i - si.peek());
                }
            }
        }
        return max;
    }

    public int longestValidParentheses(String s) {
        if (s == null || s.length() <= 1) {
            return 0;
        }
        final int SN = s.length();
        int max = 0;
        int[] dp = new int[SN];
        for (int i = 1;i < SN;++i) {
            if (s.charAt(i) == ')'){
                if (s.charAt(i - 1) == '(') {
                    dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
                } else if (i - 1 - dp[i - 1] >= 0 && s.charAt(i - 1 - dp[i - 1]) == '(') {
                    if (i - 2 - dp[i - 1] >= 0) {
                        dp[i] = dp[i - 2 - dp[i - 1]] + 2 + dp[i - 1];
                    } else {
                        dp[i] = 2 + dp[i - 1];
                    }    
                }
            }
            max = Math.max(max, dp[i]);
        }
        return max;
    }

    public static void main(String[] args) {
        LeetCode0032 l32 = new LeetCode0032();
        System.out.println(")()()) 4 : " + l32.longestValidParentheses(")()())"));
        System.out.println("(() 2 : " + l32.longestValidParentheses("(()"));
        System.out.println("()(() 2 : " + l32.longestValidParentheses("()(()"));
        System.out.println("()()))()(()()) 8 : " + l32.longestValidParentheses("()()))()(()())"));
        System.out.println("() 2 : " + l32.longestValidParentheses("()"));
        System.out.println("(()()) 6 : " + l32.longestValidParentheses("(()())"));
    }
}