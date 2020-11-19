package L400;

import java.util.ArrayDeque;
import java.util.Deque;

public class LeetCode0402{
    /**
     * 比较两个数字序列，除相同左边数字外，最左边的数字越小则数小
     * 在对每一位比较时，删除已经使用过且比当前数字大的左边数字
     */
    public String removeKdigits(String num, int k) {
        if (num == null || num.isEmpty() || k >= num.length()){
            return "0";
        } else if (k <= 0){
            return num;
        }
        Deque<Character> stack = new ArrayDeque<>();
        stack.addFirst(num.charAt(0));
        int index = 1;
        for (;index < num.length() && k > 0;index++){
            char c1 = stack.getFirst();
            char c2 = num.charAt(index);
            if (c1 > c2){
                while (!stack.isEmpty() && k > 0){
                    char ct = stack.removeFirst();
                    if (ct <= c2){
                        stack.addFirst(ct);
                        break;
                    } else {
                        k--;
                    }
                }
            } 
            stack.addFirst(c2);
        }

        while (k != 0){
            stack.removeFirst();
            k--;
        }
        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()){
            sb.append(stack.removeLast());
        }
        while (index < num.length()){
            sb.append(num.charAt(index));
            index++;
        }
        return removeZero(sb.toString());  
    }

    public String removeZero(String num) {
        int index = 0;
        while (index < num.length() && num.charAt(index) == '0'){
            index++;
        }
        return (index >= num.length()) ? "0" : num.substring(index);
    }
}