import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class LeetCode0003{
    /**
     * T(n) = O(n^2) 
     * 双重遍历字符串 扩展窗口 [i,j]
     * 利用 HashSet 来存储，保证子串没有重复元素
     */
    public int lengthOfLongestSubstringDIter(String s) {
        int max = 0;
        int length = s.length();
        for (int i = 0;i < length && length - i > max;i++){
            HashSet<Character> hs = new HashSet<>(length - i);
            int temp = 0;
            int j = i;
            for (;j < length;j++){
                int size = hs.size();
                hs.add(s.charAt(j));
                if (size == hs.size()){
                    break;
                } 
            }
            temp = j - i;
            max = max < temp ? temp : max;
        }
        return max;
    }

    public int lengthOfLongestSubstring(String s) {
        int ans = 0;
        Map<Character,Integer> ci = new HashMap<>();
        int Len = s.length();
        int start = 0;
        for (int i = 0;i < Len;++i) {
            char ch = s.charAt(i);
            if (ci.containsKey(ch)) {
                int x = ci.get(ch);
                start = start <= x ? x + 1 : start;
                
            }
            ans = Math.max(ans, i - start + 1);
            ci.put(ch, i);
        }
        return ans;
    }

    public static void main(String[] args) {
        LeetCode0003 lc = new LeetCode0003();
        System.out.println("bbbbb 1 : " + lc.lengthOfLongestSubstring("bbbbb"));
        System.out.println("abcabcbb 3 : " + lc.lengthOfLongestSubstring("abcabcbb"));
        System.out.println("pwwkew 3 : " + lc.lengthOfLongestSubstring("pwwkew"));
    }
}