package L200;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class LeetCode0290{
    /**
     * 如果有相同的模式，那么经过同样的变换，结果也相同
     * 变换方法：对于同样的元素，用同一个数字代替，形成该串的的数字序列，最后比较序列是否相同
     */
    public boolean wordPatternThird(String pattern, String str) {
        int index = 1;
        int[] alpha = new int[26];
        StringBuilder sb = new StringBuilder();
        for (char ch : pattern.toCharArray()){
            if (alpha[ch - 'a'] == 0){
                alpha[ch - 'a'] = index;
                index++;
            }
            sb.append(alpha[ch - 'a']);
        }
        String pa = sb.toString();

        String[] words = str.split(" ");
        sb = new StringBuilder();
        index = 1;
        Map<String,Integer> ms = new HashMap<>();
        for (String word : words){
            if (!ms.containsKey(word)){
                ms.put(word, index);
                index++;
            }
            sb.append(ms.get(word));
        }
        String strp = sb.toString();
        
        return Objects.equals(pa, strp);   
    }

    public boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");
        if (pattern.length() != words.length) {
            return false;
        }
        Map<Character,String> match = new HashMap<>();
        for (int i = 0;i < words.length;++i) { 
            char c = pattern.charAt(i);
            if (match.containsKey(c)) { // 1. 判断当前字母是否出现
                if (!Objects.equals(match.get(c), words[i])) {
                    return false;
                }
            } else { // 2. 当前字母未出现
                // 判断当前单词是否出现过
                for (Map.Entry<Character,String> entry : match.entrySet()) {
                    if (Objects.equals(entry.getValue(), words[i])) {
                        return false;
                    }
                }
                match.put(c, words[i]);
            }
        }
        return true;
    }
}