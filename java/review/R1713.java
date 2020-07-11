package review;

import java.util.Arrays;

public class R1713 {
    private class TrieNode {
        public boolean leaf;
        public TrieNode[] letters;

        public TrieNode() {
            leaf = false;
            letters = new TrieNode[26];
        }
    }

    private TrieNode root = new TrieNode();

    private void insert(String str) {
        TrieNode cur = root;
        for (char ch : str.toCharArray()) {
            if (cur.letters[ch - 'a'] == null) {
                cur.letters[ch - 'a'] = new TrieNode();
            }
            cur = cur.letters[ch - 'a'];
        }
        cur.leaf = true;
    }

    private boolean search(char[] chs,int left, int right) {
        TrieNode cur = root;
        for (int i = left;i <= right;++i) {
            if (cur.letters[chs[i] - 'a'] == null) {
                return false;
            }
            cur = cur.letters[chs[i] - 'a'];
        }
        return cur.leaf;
    }
   
    public int respace2D_TLE(String[] dictionary, String sentence) {
        if (dictionary == null || dictionary.length == 0) {
            return sentence == null ? 0 : sentence.length();
        } else if (sentence == null || sentence.length() == 0) {
            return 0;
        }
        for (String str : dictionary) {
            insert(str);
        }
        char[] chars = sentence.toCharArray();
        int[][] dp = new int[chars.length][chars.length];
        for (int i = 0;i < chars.length;++i) {
            for (int j = 0;j < chars.length;++j) {
                dp[i][j] = -1;
            }
        }
        return unrecognizedLetters(chars, 0, chars.length - 1, dp);
    }

    private int unrecognizedLetters(char[] chars, int left, int right, int[][] dp) {
        if (left > right) {
            return 0;
        } else if (dp[left][right] != -1) {
            return dp[left][right];
        } else if (search(chars, left, right)) {
            dp[left][right] = 0;
            return 0;
        } else if (left == right) {
            dp[left][right] = 1;
            return 1;
        }
        dp[left][right] = Integer.MAX_VALUE;
        for (int i = left;i < right;++i) {
            dp[left][right] = Math.min(dp[left][right], 
                   unrecognizedLetters(chars, left, i, dp) + unrecognizedLetters(chars, i + 1, right, dp));
        }
        return dp[left][right];
    }

    public int respace(String[] dictionary, String sentence) {
        if (dictionary == null || dictionary.length == 0) {
            return sentence == null ? 0 : sentence.length();
        } else if (sentence == null || sentence.length() == 0) {
            return 0;
        }
        for (String str : dictionary) {
            insert(str);
        }
        char[] chars = sentence.toCharArray();
        int[] dp = new int[chars.length + 1];
        Arrays.fill(dp, 100002);
        dp[0] = 0;
        for (int i = 1;i <= chars.length;++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = i;j >= 1;--j) {
                if (search(chars, j - 1, i - 1)) {
                    dp[i] = Math.min(dp[j - 1], dp[i]);
                }
            }
        }
        return dp[chars.length];
    }
}