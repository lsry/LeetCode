package L000;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0017{
    public static final char[][] digLetter = {{' '},{' '},{'a','b','c'},{'d','e','f'},{'g','h','i'},
                          {'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if (digits == null || digits.length() == 0) {
            return res;
        }
        char[] chars = new char[digits.length()];
        dfs(digits, 0, res, chars);
        return res;
    }

    private void dfs(String digits,int index,List<String> res,char[] sBuilder) {
        if (index >= digits.length()) {
            res.add(String.valueOf(sBuilder));
        }
        int digit = digits.charAt(index) - '0';
        for (char c : digLetter[digit]) {
            sBuilder[index] = c;
            dfs(digits, index + 1, res, sBuilder);
        }
    }

    // 回溯法
    // 自底向上构造部分解，然后将当前解分配到已形成的部分解中
    public List<String> letterCombinationsSubstr(String digits) {
        List<String> ls = new ArrayList<>();
        if (digits != null && digits.length() > 0){
            char c = digits.charAt(0);
            List<String> lt = letterCombinationsSubstr(digits.substring(1));
            for (int i = 0;i < digLetter[c-'0'].length;i++){
                String s = String.valueOf(digLetter[c-'0'][i]);
                if (lt != null && lt.size() > 0){
                    for (String slt : lt){
                        ls.add(s + slt);
                    }
                } else {
                    ls.add(s);
                }
            }
        }
        return ls;
    }

    public static void main(String[] args) {
        
    }
}