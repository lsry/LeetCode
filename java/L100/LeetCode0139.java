package L100;

import java.util.List;
import java.util.Objects;

public class LeetCode0139 {
    public boolean wordBreak(String s, List<String> wordDict) {
        if (s == null || s.length() == 0) {
            return true;
        } else if (wordDict.size() == 0) {
            return false;
        }
        int[] dp = new int[s.length()];
        return validate(s, wordDict, s.length() - 1, dp);
    }
    public boolean validate(String s, List<String> wordDict, int index, int[] dp) {
        if (index < 0) {
            return true;
        } else if (index != 0 && dp[index] != 0) {
            return dp[index] == 1;
        }
        boolean flag = false;
        for (String word : wordDict) {
            int start = index - word.length() + 1;
            if (start >= 0) {
                flag |= Objects.equals(s.substring(start, start + word.length()), word) 
                      && validate(s, wordDict, index - word.length(), dp);
            }
        }
        dp[index] = flag ? 1 : -1;
        return flag;
    }
}